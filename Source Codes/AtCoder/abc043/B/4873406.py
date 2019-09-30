s = input()
# s = "01B0"
# print(s[0])

ans = []
for key in range(len(s)):

    if s[key] == "0" or s[key] == "1":
        ans.append(s[key])
    if s[key] == "B" and len(ans) > 0:
        ans.pop(-1)
print("".join(ans))