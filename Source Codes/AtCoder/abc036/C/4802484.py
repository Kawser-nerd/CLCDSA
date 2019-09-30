import bisect
N = int(input())
a = [0]*N
for i in range(N):
    a[i] = int(input())
c = list(set(a[:]))
c.sort()
b = [0]*N
for i, x in enumerate(a):
    b[i] = bisect.bisect_left(c, x)
print(*b, sep='\n')