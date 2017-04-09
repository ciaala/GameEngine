/**
 * Created by crypt on 09/04/17.
 */
var wwt = function () {
    var cv = require('../../node_modules/webworker-threads/build/Release/WebWorkerThreads');
    var Worker = require('webworker-threads').Worker;

    var self = this;
    self.isDone = false;
    self.worker = new Worker(function () {
        var transform = function (message) {
            console.log('transform')
            return "Hello, " + message;
        };
        this.onmessage = function (event) {
            console.log('onmessage')
            self.postMessage(transform(event.data));
        };
    });

    self.worker.onmessage = function (event) {
        self.isDone = true;
    };
    self.start = function (data) {
        self.worker.postMessage(data);
    };


    self.start = function(data) {

        var Worker = require('webworker-threads').Worker;
// var w = new Worker('worker.js'); // Standard API

// You may also pass in a function:
        var worker = new Worker(function(){
            postMessage("I'm working before postMessage('ali').");
            this.onmessage = function(event) {
                postMessage('Hi ' + event.data);
                self.close();
            };
        });
        worker.onmessage = function(event) {
            console.log("Worker said : " + event.data);
        };
        worker.postMessage(data);
    }
};



module.exports = wwt;