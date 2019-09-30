import bisect
N,K = map(int,input().split())
A = sorted(list(map(int,input().split())))
B = sorted(list(map(int,input().split())))

minp = A[0] * B[0]
maxp = A[-1] * B[-1]
if K == 1:
    print(minp)
    exit()
if K == N*N:
    print(maxp)
    exit()

def enough(n):
    cnt = 0
    for a in A:
        cnt += bisect.bisect_right(B, n//a)
        if cnt >= K: return True
    return False

ng = 0
ok = maxp
while ok-ng > 1:
    m = (ok+ng)//2
    if enough(m):
        ok = m
    else:
        ng = m
print(ok)