S = input()
C = S.split("+")
ans = 0
for c in C:
    if "0" not in c:
        ans += 1

print(ans)