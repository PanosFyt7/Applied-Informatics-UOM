<?php
$data = array();

$host="localhost";
$uname="root";
$pass="";
$dbname="physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
mysqli_select_db($dbh, $dbname);

$sql = "select provision.id, provision.proname, provision.id_provision from provision;";

$result = mysqli_query($dbh, $sql);
		

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
$nested_data['proname']= $row['proname'];
$nested_data['id_provision'] = $row['id_provision'];
$data[$row['id']] = $nested_data;
}

mysqli_close($dbh);
header("Content-Type: application/json");
echo json_encode($data);
?>
