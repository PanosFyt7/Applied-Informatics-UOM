<?php
	//$fname = $_GET["fname"];
	//$lname = $_GET["lname"];
	$name = $_GET["name"];
	$amka = $_GET["amka"];
	$address = $_GET["address"];
	$email = $_GET["email"];
	$username = $_GET["username"];
	$password = $_GET["password"];

	$host = "localhost";
	$uname = "root";
	$pass = "";
	$dbname = "physiotherapp";
	
	$dbh = mysqli_connect($host, $uname, $pass) or die("cannot connect");
	mysqli_select_db($dbh, $dbname);
			
	$sql = "INSERT INTO credentials (username, password, id_role) VALUES ('".$username."','".$password."','2')";
	mysqli_query($dbh, $sql);
	
	$sql2 = "SELECT credentials.id FROM credentials WHERE credentials.username='".$username."' AND credentials.password='".$password."'";
	$result = mysqli_query($dbh, $sql2);
	
	$row = mysqli_fetch_assoc($result);
	$id_role = $row['id'];
	
	$sql3 = "INSERT INTO patient (name, amka, address, email, creds_id) VALUES ('".$name."', '".$amka."','".$address."', '".$email."', '".$id_role."')";
	mysqli_query($dbh, $sql3);
	
	mysqli_close($dbh);
?>
