n,m,x = map(int,input().split())
A = list(map(int,input().split()))

M = [0]*101
ans1 = 0
ans2 = 0
for a in A:
    M[a] = 1
for i in range(x,n+1):
    ans1 += M[i]
for j in range(x,-1,-1):
    ans2 += M[j]
print(min(ans1,ans2))