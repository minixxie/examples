var slugs = require("slugs")

console.log('Hi there! How are you!');
console.log(slugs('Hi there! How are you!'));
//Writes hi-there-how-are-you to console

console.log("中文會怎樣呢");
console.log(slugs("中文會怎樣呢"));

