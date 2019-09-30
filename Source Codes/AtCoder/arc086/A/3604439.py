import bisect
N, K = map(int, input().split())
a=list(map(int, input().split()))
nlis=[0]*200001
s=0
for i in range(N):
    if nlis[a[i]]==0:
        s+=1
    nlis[a[i]]+=1
nlis.sort(reverse=True)

print(sum(nlis[K:]))