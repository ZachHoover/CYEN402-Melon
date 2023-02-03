
char webSiteCont[2000];

//==========Main Page===========
char webSiteCont1[] = 
R"=====(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Login Form</title>    
    <link rel="stylesheet" type="text/css" href="css/style.css">    
</head>    
<style>
body  
{  
    margin: 0;  
    background-color:#38e000;  
    font-family: 'Arial';  
}  
.login
{  
  width: 282px;  
  overflow: hidden;  
  margin: auto;  
  margin: 20 0 0 0px;  
  padding: 60px;  
  background: #24623f;  
  border-radius: 15px ;          
}  
h2{  
    text-align: center;  
    color: #277582;  
    padding: 20px;  
}  
label{  
    color: #08ffd1;  
    font-size: 17px;  
}  
 
#Pass{  
    width: 300px;  
    height: 30px;  
    border: none;  
    border-radius: 3px;  
    padding-left: 8px;  
      
}  
#log{  
    width: 100px;  
    height: 30px;
    margin-left:200px;
    border: none;  
    border-radius: 17px;  
    color: black;
}  
</style>
<body>    
    <h2>ESP-8266 Login Page</h2><br>    
    <div class="login">    
    <div id="login" >      
    <label><b>Username</b></label>    
        <input type="uname" name="User" id="User">
        <br>
    <label><b>Password</b></label>    
        <input type="password" name="Pass" id="Pass">    
        <br><br>    
        <button onclick="sendLogin()" id="log" > Log in </button>
    </div>     
</div>    
</body>    
<SCRIPT>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':88/');
  } // end of InıtWebSocket
   function sendLogin(){
    var stringUser=document.getElementById("User").value;
    var stringPass=document.getElementById("Pass").value;
    var Credentials = 'Cred='+stringUser+'|'+stringPass;  
     //alert(stringPass);
    websock.send(Credentials);
    location.reload();
    } 
</SCRIPT>
</html>  
)=====";


//==========Pinpad Page===========
char webSiteCont2[] = 
R"=====(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Login Form</title>    
    <link rel="stylesheet" type="text/css" href="css/style.css">    
</head>    
<style>
body  
{  
    margin: 0;  
    background-color:#38e000;  
    font-family: 'Arial';  
}  
.login
{  
  width: 282px;  
  overflow: hidden;  
  margin: auto;  
  margin: 20 0 0 0px;  
  padding: 60px;  
  background: #24623f;  
  border-radius: 15px ;          
}  
h2{  
    text-align: center;  
    color: #277582;  
    padding: 20px;  
}  
label{  
    color: #08ffd1;  
    font-size: 17px;  
}  
 
#Pass{  
    width: 300px;  
    height: 30px;  
    border: none;  
    border-radius: 3px;  
    padding-left: 8px;  
      
}  
#log{  
    width: 100px;  
    height: 30px;
    margin-left:200px;
    border: none;  
    border-radius: 17px;  
    color: black;
}  
</style>
<body>    
    <h2>ESP-8266 Login Page</h2><br>    
    <div class="login">    
    <div id="login" >      
    <label><b>Resistor</b></label>    
        <h3>Connect resistor, then click "Log in"</h2><br>     
        <br><br>    
        <button onclick="sendRes()" id="log" > Log in </button>
    </div>     
</div>    
</body>    
<SCRIPT>
    InitWebSocket()
    function InitWebSocket()
    {
    websock = new WebSocket('ws://'+window.location.hostname+':88/');
    }
    function sendRes(){
      websock.send("Res");
      location.reload();
    } 
</SCRIPT>
</html>  
)=====";




//==========Info Page===========
char webSiteCont3[]  = 
R"=====(
<!DOCTYPE HTML>
<HTML>
<META name='viewport' content='width=device-width, initial-scale=1'>
<SCRIPT>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':88/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);
       document.getElementById('btn').innerHTML = JSONobj.Data;
    } // end of onmessage
      
  } // end of InıtWebSocket
  
  setInterval(function(){ location.reload();},1000*5);
</SCRIPT>
<style> 
#btn{
    position:relative;
    top:200px;
    width: 300px;
    margin: auto;  
    font-size: 100px;
  }
</style>
<BODY>
  <div id="btn"> </div>
</BODY>
</HTML>
)=====";
