def inpl():
    return list(map(int, input().split()))


S = input()

ans = 0
g = 0
p = 0
for s in S:
    if g == p:
        g += 1
        if s == "g":
            pass
        elif s == "p":
            ans -= 1
    else:
        p += 1
        if s == "g":
            ans += 1
        elif s == "p":
            pass
print(ans)