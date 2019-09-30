import sys
s = input()
if s == 'a':
    print(-1)
    sys.exit()
if s[0] != 'a':
#    print(chr(ord(s[0])-1))
    print('a')
    sys.exit()
print(s[:1])