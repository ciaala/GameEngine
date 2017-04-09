/**
 * Created by crypt on 09/04/17.
 */

/**
 *
 * @param number{int}
 * @param primes{Array}
 * @param lastPrimeIndex{int}
 */
var prime = function (MaxThreads) {
    if (MaxThreads === undefined || MaxThreads === null) {
        console.log("MaxThreads is undefined");
        MaxThreads = 4;
    }
    var async = require('async');
    var MAX_THREADS = MaxThreads;
    var self = this;
    var primes = [2];
    var lastPrimeIndex = 0;
//const MAX_VALUE = 1299709
    var counterToNextIndex = Math.pow(primes[0], 2) - 3;
    var even = false;

    self.isDone = false;
    self.check_prime_debug = function (number, primes, lastPrimeIndex) {
        var result = check_prime(number, primes, lastPrimeIndex);
        console.log('check (candidate ' + number + ', primes:' + primes.slice(0, lastPrimeIndex).toString() + ') ->' + result);
        return result;
    };

    /**
     *
     * @param number{int}
     * @param primes{Array}
     * @param firstPrimeIndex{int}
     * @param lastPrimeIndex{int}
     */
    self.check_prime = function (number, primes, firstPrimeIndex, lastPrimeIndex) {
        for (var j = firstPrimeIndex; j <= lastPrimeIndex; j++) {
            if ((number % primes[j]) === 0) {
                return false;
            }
        }
        return true;
    };
    self.doNothing = function () {
        var data = "";
        for (var i = 0; i < arguments.length; i++) {
            data = data + ", " + arguments[i]
        }
        console.log(arguments[0] + ", " + arguments[2] + ", " + arguments[3]);
        return false;
    };

    self.check_parallel_prime = function (i, primes, lastPrimeIndex) {
        var elementCount = Math.floor(lastPrimeIndex / (MAX_THREADS + 1));
        var isParallelDone = false;
        var finalResult = true;
        var tasks = [];
        for (var thread = 0; thread < MAX_THREADS; thread++) {
            var asyncTask = (function (start, end) {
                return function (callback) {
                    callback(null, self.check_prime(i, primes, start, end));
                }
            })(thread * elementCount, (thread + 1) * elementCount);
            tasks.push(asyncTask);
        }
        tasks.push(function (callback) {
                var isPrime = self.check_prime(i, primes, thread * elementCount, lastPrimeIndex);
                if (isPrime) {
                    callback(null, true);
                } else {
                    callback(false, false);
                }
            }
        );
        async.parallel(tasks, function (error, results) {
            if (error !== null && error !== undefined) {
                finalResult = false;
            } else {
                for (var i = 0; finalResult && (i < results.length); i++) {
                    finalResult = finalResult && results[i];
                }
            }
            isParallelDone = true;
        });
        while (!isParallelDone) {

        }
        //console.log(i + " -> " + finalResult);
        return finalResult;
    };
    self.start = function (MAX_VALUE) {
        for (var i = 3; primes.length < MAX_VALUE; i++, even = !even) {

            //var maxDividend = Math.floor(Math.sqrt(i))
            var isPrime = false;
            if (!even) {

                if (i > 100001) {
                    isPrime = self.check_parallel_prime(i, primes, lastPrimeIndex);
                } else {
                    isPrime = self.check_prime(i, primes, 0, lastPrimeIndex);
                }
                //console.log(i + " - " + primes[lastPrimeIndex] + " - " + counterToNextIndex);
            }
            if (isPrime) {
                primes.push(i);
            }

            counterToNextIndex--;

            if (counterToNextIndex === 0) {
                lastPrimeIndex++;
                counterToNextIndex = Math.pow(primes[lastPrimeIndex], 2) - i;
            }
        }
        self.resultAnalyser();
    }
    self.resultAnalyser = function () {
        console.log("Primes discovered: " + primes.length + ', last: ' + primes[primes.length - 1]);
        self.isDone = true;
    }

};

module.exports = prime;
