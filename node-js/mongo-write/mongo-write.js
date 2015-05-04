var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/test3'); //no need to create db in advance

var TodoSchema = new mongoose.Schema({ //no need to create table in advance
  name: String,
  completed: Boolean,
  note: String,
  updated_at: { type: Date, default: Date.now },
});
var Todo = mongoose.model('Todo', TodoSchema);




var http = require('http');
var express = require('express');

var app = express();
app.set('port', process.env.PORT || 3000);


app.get('/todo/create/', function (req, res) {
	var todo = new Todo({name: 'Master NodeJS', completed: false, note: 'Getting there...'});

	todo.save(function(err){
		var isSuccess = false;
		if(err)
		{
			console.log(err);
			isSuccess = false;
		}
		else
		{
			console.log(todo);
			isSuccess = true;
		}

		res.writeHead(200, {'Content-Type': 'application/json'});
		res.end(JSON.stringify({
			"number": 3,
			"string": "hello world!",
			"id": todo._id,
			"isSuccess": isSuccess,
		}));
	});
});

http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});



