import re
s = input()
regex = r'^(ch|[oku])*$'
pattern = re.compile(regex)
matchObj = pattern.match(s)
print("YES" if matchObj else "NO")