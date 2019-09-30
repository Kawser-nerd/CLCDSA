N,M,C=list(map(int,input().split()))
B=list(map(int,input().split()))

a=[]
for i in range(N):
    a.append(list(map(int,input().split())))
cnt=0
for k in range(N):
    sum=0
    for j in range(M):
        sum+=a[k][j]*B[j]

    if sum+C > 0:
        cnt+=1

print(cnt)