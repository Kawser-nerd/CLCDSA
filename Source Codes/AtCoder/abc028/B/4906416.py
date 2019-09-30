from collections import Counter
s = Counter(input())
for c in ['A', 'B', 'C', 'D', 'E']:
    print(s[c], end=' ')
print(s['F'])