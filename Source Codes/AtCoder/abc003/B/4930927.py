import sys
s = input()
t = input()
at = ['a', 't','c','o','d', 'e', 'r']
for i in range(len(s)):
    if s[i] != t[i]:
        if s[i] == '@' or t[i] == '@':
            if s[i] in at or t[i] in at:
                continue
        print('You will lose')
        sys.exit()
print('You can win')