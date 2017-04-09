/**
 * Created by crypt on 09/04/17.
 */
var async_test = function () {
    var async = require('async');
    var self = this;
    self.isDone = false;
    self.start = function (concurrency) {

        var asyncTasks = new Array(concurrency);
        for (var i = 0; i < concurrency; i++) {
            asyncTasks[i] = (function (j) {
                var k = j;
                return function (callback) {
                    callback(null, Math.pow(k, 2));
                }
            })(i);
        }
        async.parallel(asyncTasks,
            function (err, results) {
                var resultToString = function (index) {
                    return "results[" + index + "] -> " + results[index];
                };
                console.log("Done: " + resultToString(results.length - 1) + ", " + resultToString(results.length - 2));
                self.timeCompleted = new Date();
                self.isDone = true;
            });
    };
};

module.exports = async_test;
