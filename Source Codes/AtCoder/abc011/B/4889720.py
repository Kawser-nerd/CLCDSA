s = list(input())
s[0] = s[0].upper()
for i in range(1, len(s)):
    s[i] = s[i].lower()
print("".join(s))