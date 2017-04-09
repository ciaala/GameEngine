/**
 * Created by crypt on 09/04/17.
 */
var app = function () {
    var self = this;
    var async_test = require('./async_test');
    self.run = function () {

        console.log('loading async_test');
        var at = new async_test();
        at.start(Math.pow(10, 6));

        while (!at.isDone) {
        }
    }
};
module.exports = app;