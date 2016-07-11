from hypothesis import given, settings
from hypothesis.strategies import integers

@settings(max_examples=1000)
@given(integers(), integers())
def test_sum_hypothesis(a, b):
    assert sum(a, b) == a + b

def test_sum():
    assert sum(1, 1) == 2

def sum(a, b):
    return a + b
