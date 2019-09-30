s = input()
if len(s)==1:
    print(s.upper())
else:
    print(s[0].upper()+s[1:].lower())