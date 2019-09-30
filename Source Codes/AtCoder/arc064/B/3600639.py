s = input()
if ((len(s)%2)+(s[0]==s[-1]))%2:
    print('First')
else:
    print('Second')