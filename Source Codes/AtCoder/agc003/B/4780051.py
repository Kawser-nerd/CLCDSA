N=int(input())
A=[int(input()) for i in range(N)]

res=0
cnt=0
for i in range(N):
    if A[i]==0:
        res+=cnt
        cnt=0
    else:
        cnt=(cnt+(A[i]%2))%2
res+=cnt
print((sum(A)-res)//2)