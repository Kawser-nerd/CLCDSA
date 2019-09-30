s = input()
l = len(s)
for i in range(l - 2 + l % 2, 0, -2):
    if s[:i // 2] == s[i // 2:i]:
        print(i)
        break