N = int(input())
A = list(map(int, input().split()))
ma = max(A)
mi = min(A)
if ma-mi > 1:
    print("No")
    exit()
if ma-mi == 0 and N-1 == ma:
    print("Yes")
    exit()
d = N-ma
cma = A.count(ma)
if d+1 <= cma <= d*2:
    print("Yes")
else:
    print("No")