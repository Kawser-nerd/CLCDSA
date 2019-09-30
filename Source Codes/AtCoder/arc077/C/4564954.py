from itertools import accumulate
def acc(X): return list(accumulate(X))

N, M = map(int, input().split())
A = [int(a)-1 for a in input().split()]

X = [0] * M # 1,1,1,...
Y = [0] * M # 1,2,3,...

def tri(l, r, a = 1):
    if l < M:
        Y[l] += a
    if r + 1 < M:
        Y[r+1] -= a
        X[r+1] -= (r-l+1) * a

def box(l, r, a = 1):
    if l < M:
        X[l] += a
    if r + 1< M:
        X[r+1] -= a
    
def calc(a, b):
    if a <= b - 2:
        tri(a+2, b)
    elif a > b and a <= b + M - 2:
        tri(a+2, M-1)
        tri(0, b)
        box(0, b, -a+M-2)
        
    # print(a, b, X, Y, rev())

def rev():
    ret = acc(Y)
    ret = [X[i] + ret[i] for i in range(M)]
    return acc(ret)
    
ans = 0
for i in range(1, N):
    ans += (A[i] - A[i-1]) % M
    calc(A[i-1], A[i])

X = rev()
# print(X)
ans -= max(X)
print(ans)