/**
 * Created by crypt on 06/04/17.
 */
'use strict'
if (global.debugModules) {

}
var moduleName = "[GameEngine JavaScript Environment] execution time";
// var moduleStartTime = new Date();

// console.log(moduleName + "Starting: " + moduleStartTime);
console.time(moduleName);
var app = require('./app.js');
console.log('app is running');
new app().run();
// var moduleStopTime = new Date();
// console.log(moduleName + "Stopping: " + moduleStopTime);
// var elapsed = (moduleStopTime.getTime() - moduleStartTime.getTime()) / 1000;
// console.log(moduleName + "Run for: " + elapsed + 's');
console.timeEnd(moduleName);