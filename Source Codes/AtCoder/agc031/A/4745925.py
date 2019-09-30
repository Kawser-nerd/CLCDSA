from collections import Counter
N = int(input())
S = input()
MOD = 10**9+7

ctr = Counter(S)
ans = 1
for v in ctr.values():
    ans *= (v+1)
ans -= 1
print(ans%MOD)