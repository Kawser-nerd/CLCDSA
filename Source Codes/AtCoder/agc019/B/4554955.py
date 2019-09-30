S = input()
N = len(S)
ans = 1 + N*(N-1)//2
ct = [0] * 26
for c in S:
    i = ord(c) - ord('a')
    ct[i] += 1

for a in ct:
    ans -= a*(a-1)//2
print(ans)