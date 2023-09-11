<?php
// Database configuration
$servername = "localhost";
$username = "root";
$password = "";
$dbName = "physiotherapp";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbName);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Extract data from the HTTP POST request
$name = $_POST['name'];
$address = $_POST['address'];
$amka = $_POST['amka'];
$phone = $_POST['phone'];
$email = $_POST['email'];

// Prepare the SQL statement with a prepared statement
$sql= "insert into patient(name,address,amka,phonenumber,email) values('".$name."','".$address."','".$amka."','".$phone."','".$email."' )";

// Perform the database insertion operation
if ($result=mysqli_query($conn,$sql)) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

// Close connection
mysqli_close($conn);
?>
