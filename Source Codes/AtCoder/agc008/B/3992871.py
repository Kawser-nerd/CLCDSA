N,K=map(int,input().split())
a=list(map(int,input().split()))

M1=0
for i in range(N):
    if a[i]>=0:
        M1+=a[i]
        
s=0
for i in range(K):
    s+=max(0,a[i])
m1=s
for i in range(N-K):
    s=s+max(0,a[K+i])-max(0,a[i])
    if m1>s:
        m1=s

s=0

for i in range(K):
    s+=min(0,a[i])
m2=s
for i in range(N-K):
    s=s+min(0,a[K+i])-min(0,a[i])
    if m2<s:
        m2=s
print(max(M1-m1,M1+m2))