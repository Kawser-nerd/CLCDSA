s = input()
print([ c != d for c, d in zip(s[:-1], s[1:])].count(True))