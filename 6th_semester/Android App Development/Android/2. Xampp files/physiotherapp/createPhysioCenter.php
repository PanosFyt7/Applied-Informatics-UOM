<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "physiotherapp";

// Create connection
$conn =mysqli_connect($servername, $username, $password, $dbname);

// Extract data from the HTTP POST request
$name = $_POST["name"];
$address = $_POST["address"];
$afm = $_POST["afm"];
$username = $_POST["username"];
$password = $_POST["password"];

// Perform the database insertion operation

$sql2= "insert into credentials(username, password, id_role) values ('".$username."','".$password."','1');";

$result = mysqli_query($conn, $sql2);

$sql3 = "SELECT id FROM credentials where username='".$username."' AND password='".$password."' ;";

$result = mysqli_query($conn, $sql3);

$row = mysqli_fetch_assoc($result);
	$id = $row['id'];

$sql= "insert into physiotherapy_centre(phyname,address,afm, creds_id) values('".$name."','".$address."','".$afm."', '".$id."')";

mysqli_query($conn, $sql);

if ($result=mysqli_query($conn,$sql)) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

if ($result=mysqli_query($conn,$sql2)) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
// Close connection
$conn->close();
?>


