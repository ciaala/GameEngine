/**
 * Created by crypt on 09/04/17.
 */
var app = function () {
    var self = this;
    //var async_test = require('./async_test');
    //var prime = require('./prime');
    var moduleId = "./prime";
    console.log("Loading module: " + moduleId);
    var entry = require(moduleId);
    self.run = function () {
        var at = new entry();
        at.start(Math.pow(10, 3));

        while (!at.isDone) {
        }
    }
};
module.exports = app;