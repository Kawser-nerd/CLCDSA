from collections import Counter
from math import factorial

N = int(input())
T = [int(input()) for _ in range(N)]

T_counted = sorted(Counter(T).items())
# print(T_counted)
time = 0
penalty = 0
for k, v in T_counted:
    for _ in range(v):
        time += k
        penalty += time

_, nums = zip(*T_counted)
r = 1
for num in nums:
    r = (r*factorial(num)) % (10**9+7)

print(penalty)
print(r)