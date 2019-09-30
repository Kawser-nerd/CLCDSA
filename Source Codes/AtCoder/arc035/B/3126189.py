from math import factorial
from collections import Counter
from itertools import accumulate
n = int(input())
t = [int(input()) for i in range(n)]
dic = Counter(t)
cnt=1
for i in dic.values():
    cnt*=factorial(i)
print(sum(accumulate(sorted(t))))
print(cnt%(10**9+7))