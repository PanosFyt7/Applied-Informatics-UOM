<?php
$comments = $_GET["comments"];
$appointmentID = $_GET["appointmentID"];
$provisionID = $_GET["provisionID"];

$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);

$sql = "INSERT INTO session (`comments`, `appointment_id`, `provision_id`) VALUES ('".$comments."', '".$appointmentID."', '".$provisionID."');";
		
$result = mysqli_query($dbh, $sql);


$sql2 = "UPDATE appointment
		SET appointment_status = 3
		WHERE id = ".$appointmentID.";";
		
$result = mysqli_query($dbh, $sql2);

// Perform the database insertion operation
if ($result) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $dbh->error;
}

// Close connection
mysqli_close($dbh);
?>
