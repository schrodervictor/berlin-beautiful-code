require('mocha-testcheck').install();
var assert = require('assert');

describe('example', function () {

  var sum = require('./example').sum;

  describe('#sum(a, b)', function() {

    it('should sum integers', function() {
      assert(sum(1, 1) === 2);
    });

    check.it('should return sum of ints', [gen.int, gen.int], function(a, b) {
      assert(sum(a, b) === a + b);
    });

  });

});
