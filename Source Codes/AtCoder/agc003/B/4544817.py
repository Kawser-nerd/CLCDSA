n=int(input())
A=[int(input()) for _ in range(n)]
cnt=0
for i in range(n-1):
    cnt+=A[i]//2
    if A[i]%2 and A[i+1]:
        cnt+=1
        A[i+1]-=1
cnt+=A[-1]//2
print(cnt)