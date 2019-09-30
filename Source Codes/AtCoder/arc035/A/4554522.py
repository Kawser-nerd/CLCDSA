s=input()
d=s[::-1]
for i in range(len(s)):
    if s[i]!=d[i] and s[i]!="*" and d[i]!="*":
        print("NO")
        break
else:
    print("YES")