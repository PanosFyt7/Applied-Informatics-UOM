<?php
	$data = array();
	$amka = $_GET["amka"];
	
	$host="localhost";
	$uname="root";
	$pass="";
	$dbname="physiotherapp";

	$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
	mysqli_select_db($dbh, $dbname);

	$sql = "SELECT p.name, a.date, pr.proname, pr.cost, s.id
			FROM patient p 
			JOIN appointment a ON p.id = a.patient_id
			JOIN session s ON a.id = s.appointment_id
			JOIN provision pr ON s.provision_id = pr.id
			WHERE p.amka = ".$amka.";";
		
	$result = mysqli_query($dbh, $sql);
	
	    if ($result) {
        // Check if any rows were returned
        if (mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_array($result)) {
			$nested_data = array();
			$nested_data['name']= $row['name'];
			$nested_data['date']= $row['date'];
			$nested_data['cost']= $row['cost'];
			$nested_data['proname'] = $row['proname'];
			$data[$row['id']] = $nested_data;
			}
		} else {
				$data["error"] = "Δεν υπάρχει ασθενή με αυτό το ΑΜΚΑ" . mysqli_error($dbh);
        }
    } else {
        // Query execution failed
        $data["error"] = "Error: " . mysqli_error($dbh);
    }
	mysqli_close($dbh);
	header("Content-Type: application/json");
	echo json_encode($data);
?>