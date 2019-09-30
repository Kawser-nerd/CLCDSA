S = input()

ans = 0
for a, b in zip(S, S[1:]):
    if a != b:
        ans += 1

print(ans)