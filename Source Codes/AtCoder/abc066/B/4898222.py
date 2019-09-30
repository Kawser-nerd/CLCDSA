s = input()
found = 0
for i in range(len(s)):
    if i % 2 == 0 and i >= 2:
        t = s[:i//2]
        t2 = s[i//2:i]
        if t == t2:
            found = i
print(found)