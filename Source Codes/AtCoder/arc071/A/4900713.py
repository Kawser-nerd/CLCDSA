from collections import defaultdict

n = int(input())

total = None
for i in range(n):
    S = defaultdict(int)
    for s in input():
        S[s] += 1

    if i == 0:
        total = S
        continue

    keys = list(total.keys())
    for k in keys:
        if k in S:
            total[k] = min(total[k], S[k])
        else:
            total.pop(k)

chars = []
for k, c in total.items():
    chars.extend([k]*c)

print(''.join(sorted(chars)))