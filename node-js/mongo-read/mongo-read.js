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
var base64 = require('base64-js');

var app = express();
app.set('port', process.env.PORT || 3000);


app.get('/todo/:todoId/', function (req, res) {
	console.log("todoId=" + req.params.todoId);

	var todoId = mongoose.Types.ObjectId( req.params.todoId );

	Todo.findById(todoId, function (err, todo) {
		if (err) return console.error(err);
		console.log(todo);

		res.writeHead(200, {'Content-Type': 'application/json'});
		res.end(JSON.stringify({
			"isSuccess": true,
			"todo": todo,
		}));
	});
});

http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});



