N,A,B,C = list(map(int,input().split()))
L = [int(input()) for i in range(N)]
MIN = 99999999999
def solve(a,b,c,an,bn,cn,k):
    global MIN
    if k == N:
        if not (an == 0 or bn == 0 or cn == 0):
            MIN = min(MIN,abs(A-a)+abs(B-b)+abs(C-c)+10*(an+bn+cn-3))
        return
    else:
        solve(a+L[k],b,c,an+1,bn,cn,k+1)
        solve(a,b+L[k],c,an,bn+1,cn,k+1)
        solve(a,b,c+L[k],an,bn,cn+1,k+1)
        solve(a,b,c,an,bn,cn,k+1)
solve(0,0,0,0,0,0,0)
print(MIN)