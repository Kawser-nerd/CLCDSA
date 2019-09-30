L,R=map(int,input().split())
l=list(map(int,input().split()))
r=list(map(int,input().split()))

AL=[0 for i in range(41)]
AR=[0 for i in range(41)]

for i in range(L):
    AL[l[i]]+=1
for i in range(R):
    AR[r[i]]+=1

ans=0

for i in range(41):
    ans+=min(AL[i],AR[i])
print(ans)