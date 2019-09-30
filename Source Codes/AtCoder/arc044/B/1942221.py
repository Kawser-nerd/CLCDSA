from collections import Counter

N = int(input())
src = list(map(int,input().split()))
MOD = 10**9+7

if src[0] != 0:
    print(0)
    exit()

ctr = Counter(src)
if ctr[0] > 1:
    print(0)
    exit()

maxn = max(ctr.keys())
ans = n = 1
while n <= maxn:
    if ctr[n] == 0:
        print(0)
        exit()
    tmp = (pow(2,ctr[n-1],MOD) - 1) % MOD
    ans = (ans * pow(tmp,ctr[n],MOD)) % MOD
    n += 1

for v in ctr.values():
    e = v*(v-1)//2
    ans = (ans * pow(2,e,MOD)) % MOD
print(ans)