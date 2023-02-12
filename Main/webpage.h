
char webSiteCont[2000];

//==========Main Page===========
const char page_login[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Melon</title>    
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
 
input{  
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
    <h2>Melon</h2><br>    
    <div class="login">    
    <div id="login" >    
    <form action="/login">
    <label><b>Username</b></label>    
        <input type="uname" name="User" id="User">
        <br>
    <label><b>Password</b></label>    
        <input type="password" name="Pass" id="Pass">    
        <br><br><h2>Make sure your ID card is connected before hitting login.</h2><br>    
        <input type="submit" id="log" value="Login">
    </form>
    </div>     
</div>    
</body>    
<SCRIPT>
</SCRIPT>
</html>  
)rawliteral";


const char page_authed[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>
<head>
</head>
<style>
</style>
<body>
</body>
<SCRIPT>
</SCRIPT>
</html>
)rawliteral";


//PM, DD, DNI, DE, AM
//==========PM Page===========
const char page_pm[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>
    <meta http-equiv="refresh" content="0; url=https://www.youtube.com/watch?v=jfKfPfyJRdk" /> 
</head>    
<style>
</style>
<body>    
</body>    
<SCRIPT>
</SCRIPT>
</html>
)rawliteral";


//==========SD Page===========
const char page_sd[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Melon</title>    
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
    <h2>Secretary of Defense</h2><br>    
    <div class="login">    
    <div id="login" >      
    
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
)rawliteral";


//==========DNI Page===========
const char page_dni[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Melon</title>    
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
    <h2>Director of National Intelligence</h2><br>    
    <div class="login">    
    <div id="login" >      
    
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
)rawliteral";


//==========DE Page===========
const char page_de[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Melon</title>    
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
 
input{  
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
    <h2>Secretary of Energy</h2><br>
    
    <div class="login">    
    <div id="login" >      
    <label><b>Power Production</b></label>
        <h1 id="rev">%POWERPROD%</h1><br>
    <label><b>Set Speed</b></label>
    <form action="/de/speed">
        <input type="number" name="Speed" id="Speed" min="0" max="1024">
        <br><br>
        <input type="submit" id="log" value="Set Speed">
        <br>
    </div>     
    </div>    
</body>    
<SCRIPT>
</SCRIPT>
</html>
)rawliteral";

//==========AM Page===========
const char page_am[] PROGMEM = R"rawliteral(
<!DOCTYPE html>    
<html>    
<head>    
    <title>Melon</title>    
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
    <h2>Ambassador</h2><br>    
    <div class="login">    
    <div id="login" >      
    <label><b>Temperature</b></label>
    <h1 id="rev">%TEMPERATURE%</h1><br>
    <label><b>Humidity</b></label>
    <h1 id="rev">%HUMIDITY%</h1><br>
    </div>     
    </div>    
</body>    
<SCRIPT>
</SCRIPT>
</html>
)rawliteral";
