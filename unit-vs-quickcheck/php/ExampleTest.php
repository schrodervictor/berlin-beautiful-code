<?php
require_once 'vendor/autoload.php';
require_once 'Example.php';

use QCheck\Generator as Gen;
use QCheck\Quick;

class ExampleTest extends PHPUnit_Framework_TestCase
{
    public function test()
    {
        $hypothesis = Gen::forAll(
            [Gen::ints(), Gen::ints()],
            function($a, $b) {
                return Example::sum($a, $b) === $a + $b;
            }
        );

        $check = Quick::check(100, $hypothesis);
        $fail = array_key_exists('fail', $check) ? $check['fail'] : [];
        $shrunk = array_key_exists('shrunk', $check) ? $check['shrunk'] : [];

        $message = 'should hold given: ' . json_encode($fail)
            . PHP_EOL . 'shrunked: ' . json_encode($shrunk);

        $this->assertTrue($check['result'], $message);
    }

}
