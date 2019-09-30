import re
S = input()
print('YES') if re.match(r".*(i|I).*(c|C).*(t|T).*", S) else print('NO')