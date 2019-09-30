N = int(input())
S = input()
MOD = 10**9 + 7

chars = [1] * 30

for s in S:
    chars[ord(s)-97] += 1
    
#print(chars)

res = 1
for c in chars:
    res = (res*c)%MOD
res = (res-1)%MOD

print(res)