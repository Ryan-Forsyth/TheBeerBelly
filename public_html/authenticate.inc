<?php
session_start();
require_once('db.inc');
require_once('redirect.inc');
if(!empty($_POST['user']) && !empty($_POST['pass'])) {
 $username = strtolower(trim($_POST['user']));
 $password = trim($_POST['pass']);
 $password= hash('sha256',substr($username,0,3).$password);
 $sql="SELECT Username FROM Users where username= ? and password=?;";
 $stmt =  mysqli_prepare($db, $sql);
 $stmt-> bind_param('ss',$username,$password);
 $stmt->execute();
 $stmt->bind_result($User);
 $stmt->fetch();
 if(!empty($_GET['logoff'])) 
 	$_SESSION['user'] = null;
 if(!empty($User))
 	$_SESSION['user'] = $User;
 else
 {
 	$_SESSION['user'] = null;
 }
 $stmt->close();
}
if(empty($_SESSION['user'])){
 redirect('login.html');
}
?>