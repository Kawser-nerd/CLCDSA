s = input()
ans = ''
import re

while len(s) > 0:
    m = re.match(r'(.)\1+', s)
    if m:
        ans += s[0] + str(m.end())
        s = s[m.end():]
    else:
        ans += s[0] + '1'
        s = s[1:]
print(ans)