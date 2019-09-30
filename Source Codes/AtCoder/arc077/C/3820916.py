import itertools
def inpl(): return [int(i) for i in input().split()]

n, m = inpl()
a = [int(i)-1 for i in input().split()]
tans = [0]*2*m
Mi = []
Si = 0
for a0, a1 in zip(a, a[1:]):
    if a1 < a0:
        a1 += m
    tans[a0+2] += 1
    tans[a1+1] -= 1
    Mi.append((a1+1, 1+a0-a1))
    Si += a1 - a0
tans = list(itertools.accumulate(tans))
for x, v in Mi:
    tans[x] += v
tans = list(itertools.accumulate(tans))
ans = [0]*m
for i, v in enumerate(tans):
    ans[i%m] += v
print(Si - max(ans))