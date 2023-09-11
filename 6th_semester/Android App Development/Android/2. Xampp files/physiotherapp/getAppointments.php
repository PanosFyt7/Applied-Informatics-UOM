<?php
$data = array();
$id = $_GET["id"];
$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);

$sql = "SELECT p.name, p.phonenumber, a.date, a.time, a.id, a.appointment_status
        FROM appointment a
        JOIN patient p ON a.patient_id = p.id
		JOIN physiotherapy_centre pc ON a.center_id = pc.id
        WHERE a.appointment_status = 2 AND a.center_id = ".$id."
		ORDER BY a.date ASC";
		
$result = mysqli_query($dbh, $sql);

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
$nested_data['name']= $row['name'];
$nested_data['phonenumber'] = $row['phonenumber'];
$nested_data['date']= $row['date'];
$nested_data['time']= $row['time'];
$nested_data['appointment_status'] = $row['appointment_status'];
$data[$row['id']] = $nested_data;
}
mysqli_close($dbh);
header("Content-Type: application/json");
echo json_encode($data);
?>