from collections import Counter
w = input()
num = Counter(w)
ans = list(num.values())
if not any([i%2 for i in ans]):
    print('Yes')
else:
    print('No')