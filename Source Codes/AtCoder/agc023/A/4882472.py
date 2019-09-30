from collections import Counter
N = int(input())
A = list(map(int, input().split(" ")))
S = [0, ]
now = 0
for n in A:
    now += n
    S.append(now)
Scounter = Counter(S)
ans = 0
for c, n in Scounter.most_common():
    if n >= 2:
        ans += n*(n-1)//2
    else:
        break
print(ans)