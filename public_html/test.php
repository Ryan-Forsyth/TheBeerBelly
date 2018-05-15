<?php
include('db.inc');
$result = $db->query("select * from products");
while($row = $result->fetch_object())
{
 print_r($row);
}
?>