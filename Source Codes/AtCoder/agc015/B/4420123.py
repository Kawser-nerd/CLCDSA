s = input()
n = len(s)
ans = 0
for i, c in enumerate(s):
    ans += n-1
    if c == "U":
        ans += i
    else:
        ans += n-1 - i
print(ans)