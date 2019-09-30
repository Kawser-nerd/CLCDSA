import re
S = input()
print(re.sub(r'\D', '', S))