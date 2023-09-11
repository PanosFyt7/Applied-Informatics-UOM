<?php
    $mysql_hostname = "localhost";
    $mysql_username = "root";
    $mysql_password = ""; 
    $mysql_database = "physiotherapp";

    $code = $_GET["code"];
    $name = $_GET["name"];
    $description = $_GET["description"];
    $cost = $_GET["cost"];

    $conn = mysqli_connect($mysql_hostname, $mysql_username, $mysql_password, $mysql_database);
    
    // Εισαγωγή δεδομένων
    $insertQuery = "INSERT INTO provision (id_provision, proname, prodescription, cost) 
                    VALUES ('$code', '$name', '$description', '$cost')";
    
    if (mysqli_query($conn, $insertQuery)) {
        echo "Data inserted successfully.";
    } else {
        echo "Error inserting data: " . mysqli_error($conn);
    }

    mysqli_close($conn);
?>
