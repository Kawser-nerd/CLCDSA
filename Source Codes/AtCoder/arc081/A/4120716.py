from collections import Counter

N = int(input())
A = list(map(int, input().split()))

C = Counter(A)
l = []
for i, v in C.items():
    if v >= 2:
        l.append(i)
    if v >= 4:
        l.append(i)

if len(l) < 2:
    ans = 0
else:
    l = sorted(l, reverse=True)
    ans = l[0]*l[1]
print(ans)