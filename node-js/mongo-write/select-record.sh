#!/bin/bash 

mongo <<EOF
use test3;
db.todos.find();
EOF
