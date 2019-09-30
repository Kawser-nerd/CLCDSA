s = input()
if s[0] == s[-1] and len(s) % 2 == 0:
    print('First')
elif s[0] != s[-1] and len(s) %2 == 1:
    print('First')
else:
    print('Second')