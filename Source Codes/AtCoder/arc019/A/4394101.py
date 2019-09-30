s = input()

res = ''
for i in range(len(s)):
    if s[i] == 'O':
        res += '0'
    elif s[i] == 'D':
        res += '0'
    elif s[i] == 'I':
        res += '1'
    elif s[i] == 'Z':
        res += '2'
    elif s[i] == 'S':
        res += '5'
    elif s[i] == 'B':
        res += '8'
    else:
        res += s[i]
        
print(res)