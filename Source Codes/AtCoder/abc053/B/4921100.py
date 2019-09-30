s = input()
ans = s[s.index('A')::]
s = ans[::-1]
ans = s[s.index('Z')::]
print(len(ans))