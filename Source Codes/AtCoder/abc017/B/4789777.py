import re
s = input()

if s == "":
    print("YES")
else:
    regex = r'^((ch)|[oku])+$'
    pattern = re.compile(regex)
    matchObj = pattern.match(s)
    print("YES" if matchObj else "NO")