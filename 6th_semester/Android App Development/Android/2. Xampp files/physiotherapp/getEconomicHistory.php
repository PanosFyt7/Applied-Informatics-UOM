<?php
$data = array();
$id = $_GET["id"];

$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);

$sql = "SELECT s.id, a.date, pc.phyname, pr.proname, pr.cost, p.name
 FROM session s 
 JOIN appointment a ON a.id = s.appointment_id
 JOIN physiotherapy_centre pc ON pc.id = a.center_id 
 JOIN provision pr ON pr.id = s.provision_id
 JOIN patient p ON p.id = a.patient_id
 WHERE a.patient_id =".$id." AND a.appointment_status = 3;";
		
$result = mysqli_query($dbh, $sql);

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
$nested_data['date']= $row['date'];
$nested_data['phyname'] = $row['phyname'];
$nested_data['proname']= $row['proname'];
$nested_data['cost']= $row['cost'];
$nested_data['name']= $row['name'];
$data[$row['id']] = $nested_data;
}
mysqli_close($dbh);
header("Content-Type: application/json");
echo json_encode($data);
?>