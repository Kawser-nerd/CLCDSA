S = input()
plus = S.split("+")
ans = 0
for pl in plus:
    if pl.count("0") == 0:
        ans += 1
print(ans)