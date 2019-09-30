s = input() + "_"
ans = ""
finding = s[0]
counter = 0
for i in range(len(s)):
    if finding != s[i]:
        ans += s[i - 1]
        ans += str(counter)
        finding = s[i]
        counter = 1
    else:
        counter += 1
print(ans)