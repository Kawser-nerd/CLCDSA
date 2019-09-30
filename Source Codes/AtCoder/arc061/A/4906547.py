S = list(input())
ans = 0

for state in range(1 << len(S)-1):
    ans += eval(S[0] + ''.join(('+' if state >> i & 1 else '') + x for i, x in enumerate(S[1:])))

print(ans)