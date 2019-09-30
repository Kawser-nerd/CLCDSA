import collections
S = input()
c = collections.Counter(S)
print(c.get('+', 0) - c.get('-', 0))