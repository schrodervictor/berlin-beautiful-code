-module(prop_example).
-include_lib("proper/include/proper.hrl").

prop_all_sums() ->
    ?FORALL({A, B}, {integer(), integer()}, example:sum(A, B) =:= A + B).
