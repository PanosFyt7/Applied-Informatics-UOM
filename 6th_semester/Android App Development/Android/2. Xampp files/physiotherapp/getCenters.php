<?php
$data = array();
$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);

$sql = "select pc.phyname, pc.id from physiotherapy_centre pc";
		
$result = mysqli_query($dbh, $sql);

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
$nested_data['phyname']= $row['phyname'];
$data[$row['id']] = $nested_data;
}
mysqli_close($dbh);
header("Content-Type: application/json");
echo json_encode($data);
?>