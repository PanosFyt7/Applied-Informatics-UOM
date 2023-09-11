<?php
	$data = array();
	$id = $_GET["id"];
	$appointment_status = $_GET["appointment_status"];

	$host="localhost";
	$uname="root";
	$pass="";
	$dbname="physiotherapp";
	
	$dbh = mysqli_connect($host,$uname,$pass) or die("cannot connect");
	mysqli_select_db($dbh, $dbname);
			
	$sql = "UPDATE appointment
			SET appointment_status = " . $appointment_status ."
			WHERE id = " . $id;
	echo $sql;
	mysqli_query($dbh, $sql);
	mysqli_close($dbh);
?>