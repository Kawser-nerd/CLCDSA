stack = 0
S = input()
ans = len(S)
for c in S:
    if c == "S":
        stack += 1
    elif stack != 0:
        stack -= 1
        ans -= 2
print(ans)