s = str(input())
S = s[::-1]
for i in range(len(s)):
    if s[i] == S[i] or s[i] == "*" or S[i] == "*":
        pass
    else:
        print("NO")
        exit()
print("YES")