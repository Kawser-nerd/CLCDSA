s = input()
t = input()
safe = tuple('atcoder')

output = 'You can win'

for i in range(len(s)):
    if s[i] == t[i] or (s[i]=='@' and t[i] in safe) or (t[i]=='@' and s[i] in safe):
        pass
    else:
        output = 'You will lose'
        break

print(output)