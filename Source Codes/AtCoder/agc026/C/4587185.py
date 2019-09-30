from itertools import product, compress
from collections import Counter

N = int(input())
Ss = input()

S1s = Ss[:N]
ptn1s = [''.join(compress(S1s, sels)) for sels in product(range(2), repeat=N)]
cnt1 = Counter([(red, blue) for red, blue in zip(ptn1s, reversed(ptn1s))])

S2s = Ss[N:][::-1]
ptn2s = [''.join(compress(S2s, sels)) for sels in product(range(2), repeat=N)]
cnt2 = Counter([(red, blue) for red, blue in zip(ptn2s, reversed(ptn2s))])

ans = 0
for ptn1, num1 in cnt1.items():
    ans += num1 * cnt2[ptn1]
print(ans)