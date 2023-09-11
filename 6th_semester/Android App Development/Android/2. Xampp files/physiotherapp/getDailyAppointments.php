<?php
$data = array();
$date = $_GET["date"];
$centerID = $_GET["centerID"];


$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);


$sql = "select appointment.time, patient.name, appointment.id
		from appointment JOIN patient ON patient.id = appointment.patient_id 
		where appointment.appointment_status = 1 AND appointment.center_id =".$centerID." AND appointment.date = '".$date."';";
		
$result = mysqli_query($dbh, $sql);

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
$nested_data['time'] = $row['time'];
$nested_data['name'] = $row['name'];
$data[$row['id']] = $nested_data;
}
mysqli_close($dbh);
header("Content-Type: application/json");
echo json_encode($data);

?>
