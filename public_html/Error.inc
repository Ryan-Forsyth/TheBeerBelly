<?php
function Send_Error($message , $redirectURL)
{
	include('redirect.inc');
	$_POST['FLAG']=$message;
	redirect($redirectURL);
	
}
function Recieve_Error()
{
	if($_POST['FLAG'])
	{
		$message=$_POST['FLAG'];
		print "<script language= 'javascript'> alert(".$message.") </script>";
		unset($_Post['FLAG'];
	}
}
?>