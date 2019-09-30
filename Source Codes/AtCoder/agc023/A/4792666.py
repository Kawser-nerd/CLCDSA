N=int(input())
A=[int(i) for i in input().split()]

mp = {0:1}
for i in range(N-1):
    A[i+1]+=A[i]
for a in A:
    if a in mp:
        mp[a]+=1
    else:
        mp[a]=1
res = 0
for v in mp.values():
    res += v*(v-1)//2
print(res)