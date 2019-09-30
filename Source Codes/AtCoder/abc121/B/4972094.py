N,M,C=list(map(int,input().split()))
B=list(map(int,input().split()))

cnt=0
for _ in range(N):
    A=[int(a) for a in input().split()]
    sum=0
    for j in range(M):
        sum+=A[j]*B[j]
    if sum+C > 0:
        cnt+=1

print(cnt)