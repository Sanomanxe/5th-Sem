<?php
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
    $conn = new mysqli("127.0.0.1", "root", "", "labassignment1", 3306);

    $createTableSql = "CREATE TABLE IF NOT EXISTS student (
        id INT PRIMARY KEY,
        name VARCHAR(100) NOT NULL,
        address VARCHAR(100) NOT NULL,
        phone VARCHAR(20) NOT NULL
    )";

    $conn->query($createTableSql);

    $insertSql = "INSERT INTO student (id, name, address, phone)
                  VALUES (1, 'Suresh', 'Dallu', '9800000000')";

    if ($conn->query($insertSql)) {
        echo "Data inserted successfully";
    }

    $conn->close();
} catch (mysqli_sql_exception $e) {
    echo "Database error: " . $e->getMessage();
}
?>
