from collections import Counter
from math import factorial
from itertools import accumulate

N = int(input())
inputs = [int(input()) for _ in range(N)]

inputs.sort()

mod = 10 ** 9 + 7

counter_inputs = Counter(inputs)
counts = len(counter_inputs)

ans = 1
for value in counter_inputs.values():
    ans *= factorial(value)

print(sum(accumulate(inputs)))
print(ans % mod)