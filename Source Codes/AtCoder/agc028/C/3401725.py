from operator import itemgetter
from itertools import chain

n = int(input())
aaa = [tuple(map(int, input().split())) for _ in range(n)]
flatten = list(chain.from_iterable([(a, i), (b, i)] for i, (a, b) in enumerate(aaa)))
flatten.sort()
flag = True
picked = set()
ans = 0

for ab, i in flatten[:n]:
    if flag and i in picked:
        flag = False
    picked.add(i)
    ans += ab

if flag:
    exclude = flatten[n - 1]
    include = flatten[n]
    if exclude[1] == include[1]:
        tmp1 = include[0] - flatten[n - 2][0]
        tmp2 = flatten[n + 1][0] - exclude[0]
        ans += min(tmp1, tmp2)
    else:
        ans -= exclude[0]
        ans += include[0]

ans = min(ans, sum(map(itemgetter(0), aaa)), sum(map(itemgetter(1), aaa)))

print(ans)