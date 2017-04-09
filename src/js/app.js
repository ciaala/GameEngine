/**
 * Created by crypt on 09/04/17.
 */
var app = function () {
    var self = this;
    //var async_test = require('./async_test');
    //var prime = require('./prime');
    var entry = require("./prime");
    self.run = function () {
        var at = new entry();
        at.start(Math.pow(10, 6));

        while (!at.isDone) {
        }
    }
};
module.exports = app;