n, a, b = map(int, input().split())
c = 0
for _ in range(n):
    s, d = input().split()
    d = int(d)
    d = a if d < a else b if d > b else d
    if s == "East":
        c += d
    else:
        c -= d
if c == 0:
    ans = 0
elif c < 0:
    ans = "West" + " " + str(-c)
else:
    ans = "East" + " " + str(c)
print(ans)