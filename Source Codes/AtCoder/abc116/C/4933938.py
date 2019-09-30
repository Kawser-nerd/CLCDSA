N=int(input())
H=[int(i) for i in input().split()]
S=sum(H)
ans=0
while S>0:
    for i in range(N):
        if H[i]>0:
            break
    for j in range(i,N):
        if H[j]==0:
            break
    if j==N-1 and H[j]>0:
        j+=1
    for k in range(i,j):
        H[k]-=1
    ans+=1
    S-=j-i
print(ans)