function ordervalidate() {
var fname=document.getElementsByName('Firstname');
var lname=document.getElementsByName('Lastname');
var phone=document.getElementsByName('Phone');
var email=document.getElementsByName('Email');
var street=document.getElementsByName('Street');
var city=document.getElementsByName('City');
var state=document.getElementsByName('State');
var zip= document.getElementsByName('Zip');
 	
 	if(fname!=null && fname[0].value=='') 
 	{	
 		alert("First name field is required!");
 		return false; 
 	}
 	if(lname!=null && lname[0].value=='') 
 	{	
 		alert("Last name field is required!");
 		return false; 
 	}
 	if(phone!=null && phone[0].value=='') 
 	{	
 		alert("Phone number field is required!");
 		return false; 
 	}
 	if(email!=null && email[0].value=='') 
 	{	
 		alert("Email field is required!");
 		return false; 
 	}
 	if(street!=null && street[0].value=='')
 	{
 		alert("Street Address field is required!");
 		return false; 
 	}
 	if(city!=null &&  city[0].value=='')
 	{	
 		alert("City is a required field!");
 		return false; 
 	}
 	if(state!=null &&  state[0].value=='')
 	{	
 		alert("State is a required field!");
 		return false; 
 	}
 	if(zip!=null &&  zip[0].value=='')
 	{	
 		alert("City is a required field!");
 		return false; 
 	}
 		return true;
}