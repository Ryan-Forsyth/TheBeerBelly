<?php

function load_cart(){
	if(!empty($_COOKIE['cart']))
		$cart=unserialize($_COOKIE['cart']);
	else
		$cart=array();
	if(!is_array($cart))
		$cart=array();
	
	return $cart;
}

function show_cart($cart)
{
	$total=0;
	if(empty($cart))
		print "<div id='emptyCart'> <p> No items in Cart</p> </div>";	
	require_once('db.inc');
	
	foreach($cart as $id => $qty)
	{	
		$result=$db->query("select * from products where ID=".$id);
		$result= $result->fetch_object();
		print "<form action='cart.html' method='post'>";
		print "<input type='hidden' name='id' value='".$id."' >";
		print "<div class='CartItem'>";
		print "<ul class=CartProduct>";
		print "<li class=CartProductName><h1>".$result->Name."</h1></li>";
		print "<li class=PurchaseQuant> <h2> Quantity:</h2> ";
		print "<input type='number' name='qty' value='".$qty."'>";
		print "<button type='submit' value='Submit'>Update</button></li>";
		print "<li class=UnitPrice><h2> Unit Price: <br><br>".$result->Price."</h2> </li>";
		print "<li class=Price><h2> Price: <br><br>	$".($qty*$result->Price)."</h2></li>";
		print "</div>";
		$total=$total+($qty*$result->Price);
		print "</form>";
	}
	print "<div id='totalPrice'> <h2> Total: $".$total."</h2></div>";
	setcookie('cart',serialize($cart), time()+60*60*24*7);
}
?>