s = input().split()

ans = ""

for word in s:
    if word == "Left":
        ans += " <"
    elif word == "Right":
        ans += " >"
    else:
        ans += " A"

print(ans[1:])