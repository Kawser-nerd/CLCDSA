import re
s = input()
mermaid = ['a','i','u','e','o']
print(re.sub(r'\W', '', str([i for i in s if i not in mermaid])))