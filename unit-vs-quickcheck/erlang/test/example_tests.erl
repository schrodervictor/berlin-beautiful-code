-module(example_tests).
-include_lib("eunit/include/eunit.hrl").

sum_test_() ->
    [
        ?_assertEqual(2, example:sum(1, 1)),
        ?_assertEqual(-10, example:sum(-20, 10)),
        ?_assertEqual(7, example:sum(3, 4)),
        ?_assertEqual(7, example:sum(4, 3)),
        ?_assertEqual(1000000000, example:sum(999999999, 1))
    ].
