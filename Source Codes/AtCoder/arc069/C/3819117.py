import itertools, bisect
def inpl(): return [int(i) for i in input().split()]

N = int(input())
a = inpl()
sa = sorted(a)
acsa = list(itertools.accumulate(sa)) + [0]
acans = 0
ma = 0
ans = [0]*N
for i in range(N):
    if ma >= a[i]:
        continue
    ma = a[i]
    x = bisect.bisect_left(sa, a[i]) - 1
    ans[i] = a[i]*(N-1-x) + acsa[x] - acans
    acans += ans[i]
    
for i in ans:
    print(i)