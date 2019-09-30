import bisect
N = int(input())
L = []
def index(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return True
    else:
        return False
for i in range(N):
    L.append(int(input()))
L0 = L[::2]
L.sort()
Ls0 = L[::2]
cc = 0
for i in range((N+1)//2):
    if not index(Ls0, L0[i]):
        cc += 1
print(cc)