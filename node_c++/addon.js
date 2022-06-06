//bindings会根据binding.gyp查到对应的.node文件路径
//var addon = require('bindings')('hello');
//直接调用路径下的.node文件
var addon = require("./third_party/addon")
console.log(addon.hello1()); // 'world'
console.log(addon.add());
console.log(addon.getInfo());