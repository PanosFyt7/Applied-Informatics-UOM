<?php

$data = array();
$phone_num = $_GET["phone_num"];
$physio = $_GET["physio"];
$date = $_GET["date"];
$id = $_GET["id"];
$checkbox_text = $_GET["checkbox_text"];
$centerID = $_GET["centerID"];

$host = "localhost";
$uname = "root";
$pass = "";
$dbname = "physiotherapp";

$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
 mysqli_select_db($dbh, $dbname);

$sql = "INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '".$checkbox_text."', '".$date."', '2', '".$id."', '".$centerID."');";

mysqli_query($dbh, $sql);
mysqli_close($dbh);

?>

