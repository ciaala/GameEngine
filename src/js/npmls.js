/**
 * Created by crypt on 09/04/17.
 */
var npmls = function () {
    var self = this;
    function npmls(cb) {
        require('child_process').exec('npm ls --json', function (err, stdout, stderr) {
            if (err) return cb(err);
            cb(JSON.parse(stdout));
        });
    }
    // var sh = require("shelljs");
    // var cwd = sh.pwd();
    npmls(console.log);
};
module.exports = npmls;