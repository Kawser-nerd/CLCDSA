s = input()
s = s.replace('ch', '9')
for i in range(len(s)):
    if s[i] not in ['9', 'o', 'k', 'u']:
        break
else:
    print('YES')
    exit()
print('NO')