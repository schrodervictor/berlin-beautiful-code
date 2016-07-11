-module(example).
-export([sum/2]).

-spec sum(integer(), integer()) -> integer().
sum(A, B) -> A + B.
