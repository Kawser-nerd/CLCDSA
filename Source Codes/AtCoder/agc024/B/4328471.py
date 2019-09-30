n=int(input())
P=[int(input()) for _ in range(n)]
Q=[0]*n
for i,j in enumerate(P):
    Q[j-1]=i
cresc=1
cnt=1
for i in range(1,n):
    if Q[i-1]<Q[i]:
        cnt+=1
    else:
        cresc=max(cresc,cnt)
        cnt=1
    cresc=max(cresc,cnt)
print(n-cresc)