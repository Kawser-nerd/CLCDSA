from collections import Counter
input()
C = Counter(input())
print(sum([C[X]%2 for X in "RGB"]))