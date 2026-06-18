<?php
setcookie("user", "Sudip", time() + 3600); 

echo "Cookie is set!";

session_start();

$_SESSION["user"] = "Sudip";
$_SESSION["age"] = 20;

echo "Session is set!";
?>