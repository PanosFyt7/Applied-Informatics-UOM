<?php
$data = array();
$username = $_GET["username"];
$password = $_GET["password"];

$host = "localhost";
$uname = "root";
$pass = "";
$dbname = "physiotherapp";

$dbh = mysqli_connect($host, $uname, $pass) or die("Cannot connect");
mysqli_select_db($dbh, $dbname);

if ($username === "admin" && $password === "admin") {
    $data["id_role"] = 0;
    $data["name"] = "Π.Σ.Φ.";
    $data["id"] = 0;
} else {
    $sql = "SELECT c.id_role,
            CASE
                WHEN c.id_role = 1 THEN pc.phyname
                ELSE p.name
            END AS name,
            CASE
                WHEN c.id_role = 1 THEN pc.id
                ELSE p.id
            END AS id
            FROM credentials c
            LEFT JOIN physiotherapy_centre pc ON c.id = pc.creds_id AND c.id_role = 1
            LEFT JOIN patient p ON c.id = p.creds_id AND c.id_role = 2
            WHERE c.username='" . $username . "' AND c.password='" . $password . "';";
    $result = mysqli_query($dbh, $sql);

    if ($result) {
        // Check if any rows were returned
        if (mysqli_num_rows($result) > 0) {
            $row = mysqli_fetch_assoc($result);
            $data["id_role"] = $row["id_role"];
            $data["name"] = $row["name"];
            $data["id"] = $row["id"];
        } else {
            // No rows returned, set id_role, name, and id to null
            $data["id_role"] = 5;
            $data["name"] = "unknown";
            $data["id"] = 0;
        }
    } else {
        // Query execution failed
        $data["error"] = "Error: " . mysqli_error($dbh);
    }
}

// Close the database connection
mysqli_close($dbh);

// Return the result as JSON response
header("Content-Type: application/json");
echo json_encode($data);
?>
