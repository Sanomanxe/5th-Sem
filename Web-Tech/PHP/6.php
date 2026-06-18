<?php

mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
    $conn = new mysqli("127.0.0.1", "root", "", "labassignment1", 3306);

    for ($i = 1; $i <= 10; $i++) {

        $id = $i + 100;
        $name = "Student" . $i;
        $address = "Kathmandu Area " . $i;
        $phone = "980000000" . $i;

        $sql = "INSERT INTO student (id, name, address, phone)
                VALUES ($id, '$name', '$address', '$phone')";

        $conn->query($sql);
    }

    echo "10 student records inserted successfully";

    $conn->close();
} catch (mysqli_sql_exception $e) {
    echo "Database error: " . $e->getMessage();
}

?>
