s = input()
s = s[0].upper() +s[1:].lower() if len(s) > 1 else s.upper()
print(s)