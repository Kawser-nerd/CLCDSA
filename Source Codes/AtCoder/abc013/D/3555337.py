N,M,D = map(int,input().split())
A = list(map(int,input().split()))
a = [i+1 for i in range(N)]
for i in range(M):
    ex = A[i]-1
    a[ex],a[ex+1]=a[ex+1],a[ex]
d = [{} for i in range(32)]
for i in range(N):
    d[0][a[i]] = i+1
for i in range(2,31,2):
    for j in range(N):
        d[i][j+1] = d[i-2][d[i-2][d[i-2][d[i-2][j+1]]]]
 
def f(n,k):
    res = n
    for i in range(30,-1,-1):
        if k//(2**i)==1:
            if i%2 == 0:
                res = d[i][res]
            else:
                res = d[i-1][d[i-1][res]]
            k -= 2**i
    return res
 
for i in range(N):
    print(f(i+1,D))