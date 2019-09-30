from collections import OrderedDict
N = int(input())
A = list(map(int, input().split()))
R = {"gray": 0, "brown": 0, "green": 0, "light": 0, "blue": 0, "yellow": 0, "orange": 0, "red": 0}
S = OrderedDict([("gray", 400), ("brown", 800), ("green", 1200), ("light", 1600), ("blue", 2000), ("yellow", 2400), ("orange", 2800), ("red", 3200)])
for a in A:
    for r, s in S.items():
        if a < s:
            R[r] += 1
            break
num = len([r for r, n in R.items() if n != 0])
other = N - sum([n for r, n in R.items() if n != 0])
if num == 0:
    print(1, N)
    exit()
print(num, num + other)