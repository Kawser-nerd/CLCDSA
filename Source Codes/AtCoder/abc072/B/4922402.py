s = str(input())

result = ""
for i in range(len(s)):
    if (i + 1) % 2 != 0:
        result += s[i]
print(result)