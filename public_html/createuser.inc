<?php
include('db.inc');

if(!empty($_POST['nuser']) && !empty($_POST['npass'])) {
 $username = strtolower(trim($_POST['nuser']));
 $password = trim($_POST['npass']);
 $password= hash('sha256',substr($username,0,3).$password);
 $select="SELECT Username FROM Users Where username=?;";
 $stmt =  mysqli_prepare($db, $select);
 $stmt->bind_param('s',$username);
 $stmt->execute();
 $stmt->bind_result($User);
 $stmt->fetch();

 require_once('redirect.inc');
 if(!empty($User))
 {
 	redirect('createuser.html');
 }
 $sql="Insert into Users  (username, password) value(?,?);";
 $stmt1=mysqli_prepare($db,$sql);
 $stmt1->bind_param('ss',$username,$password);
 $stmt1->execute();
 
 redirect('login.html');
}
?>