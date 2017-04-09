/**
 * Created by crypt on 09/04/17.
 */

/**
 *
 * @param number{int}
 * @param primes{Array}
 * @param lastPrimeIndex{int}
 */
var prime = function () {
    var self = this;
    var primes = [2];
    var lastPrimeIndex = 0;
    const MAX_VALUE = Math.pow(10, 6);
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


    self.check_parallel_prime = function (i, primes, lastPrimeIndex) {
        var elementCount = primes.length() / 4;
        var tasks = [];
        for (var thread = 0; thread < 3; thread++) {
            var asyncTask = function () {
                return check_prime(i, primes, thread * elementCount, (thread + 1) * elementCount);
            };
            tasks.push(asyncTask);
        }
        tasks.push(function () {
            return check_prime(i, primes, t)
        });

    };
    self.start = function () {
        for (var i = 3; primes.length < MAX_VALUE; i++, even = !even) {

            //var maxDividend = Math.floor(Math.sqrt(i));
            if (!even) {
                if (i > 1001) {
                    isPrime = check_parallel_prime(i, primes, lastPrimeIndex);
                } else {
                    isPrime = check_prime(i, primes, 0, lastPrimeIndex);
                }
                primes.push(i);
                //console.log(i + " - " + primes[lastPrimeIndex] + " - " + counterToNextIndex);
            }
        }
        counterToNextIndex--;

        if (counterToNextIndex === 0) {
            lastPrimeIndex++;
            counterToNextIndex = Math.pow(primes[lastPrimeIndex], 2) - i;
        }
    };
    self.resultAnalyser = function () {
        console.log("Primes discovered: " + primes.length + ', last: ' + primes[primes.length - 1]);
        self.isDone = true;
    }

};

module.exports = prime;
