import re

a, b = [int(_) for _ in input().split()]
s = input()

m = re.match('[0-9]{{{0}}}-[0-9]{{{1}}}'.format(a, b), s)
print('Yes' if m else 'No')