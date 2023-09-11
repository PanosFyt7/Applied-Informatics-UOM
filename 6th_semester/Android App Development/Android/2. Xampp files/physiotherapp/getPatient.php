<?php
// Καθορίστε τον τύπο απόκρισης ως JSON
header('Content-Type: application/json');

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "physiotherapp";

// Δημιουργία σύνδεσης
$conn = new mysqli($servername, $username, $password, $dbname);

// Έλεγχος σύνδεσης
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Ανάκτηση του ΑΜΚΑ που περάστηκε από το Android Studio

$jsonData = file_get_contents('php://input');

// Μετατροπή των δεδομένων JSON σε αντικείμενο ή πίνακα
$data = json_decode($jsonData);

// Προσπελάστε τα δεδομένα JSON όπως επιθυμείτε
$amka = $data->amka;

$sql = "SELECT * FROM patient WHERE amka = '$amka'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Τα αποτελέσματα της αναζήτησης
    while ($row = $result->fetch_assoc()) {
        // Επεξεργασία των αποτελεσμάτων
        $data = array(
            'name' => $row["name"],
            'amka' => $row["amka"],
			'address' => $row["address"],
			'phonenumber' => $row["phonenumber"],
			'email' => $row["email"]
        );

        $jsonData = json_encode($data);
        // Π.χ., εμφάνιση των αποτελεσμάτων ή αποθήκευσή τους σε μια μεταβλητή για χρήση στο Android Studio
        echo $jsonData;
    }
} else {
    // Δεν βρέθηκαν αποτελέσματα
    $data = array(
        'error' => "Δεν υπάρχει χρήστης με αυτό το ΑΜΚΑ."
    );

    $jsonData = json_encode($data);

    echo $jsonData;
}

?>
