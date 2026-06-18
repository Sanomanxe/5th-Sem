<?php
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
    $conn = new mysqli("127.0.0.1", "root", "", "labassignment1", 3306);
    $sql = "SELECT * FROM student";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table border='1' cellpadding='20'><tr><th>ID</th><th>Name</th><th>Address</th><th>Phone</th></tr>";

        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["id"] . "</td><td>" . $row["name"] . "</td><td>" . $row["address"] . "</td><td>" . $row["phone"] . "</td></tr>";
        }

        echo "</table>";
    } else {
        echo "0 results";
    }

    $conn->close();
} catch (mysqli_sql_exception $e) {
    echo "Database error: " . $e->getMessage();
}
