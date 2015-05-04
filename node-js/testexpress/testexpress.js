var http = require('http'),
    express = require('express');
 
var app = express();
app.set('port', process.env.PORT || 3000); 
 
app.get('/', function (req, res) {
  res.send('<html><body><h1>Hello World</h1></body></html>');
});
app.get('/hi/', function (req, res) {
  res.send('<html><body><h1>Hello World --- HI!!</h1></body></html>');
});
 
http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
