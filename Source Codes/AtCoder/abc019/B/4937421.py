s = input()
temp = ""
ans = ""
c = 0
s += "_"
for s_ in s:
    if temp != s_:
        ans += temp
        ans += str(c)
        temp = s_
        c = 0
        c += 1
    else:
        c += 1
print(ans[1:])