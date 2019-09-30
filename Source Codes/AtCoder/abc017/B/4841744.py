import re

s = input()
s = re.sub('ch|o|k|u',"",s)
print ("YES" if s == "" else "NO")