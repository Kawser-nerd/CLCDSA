from math import log
p = float(input())
q = 1.5 * log(p * log(2) / 1.5) / log(2)
r = q + p / (2 ** (q / 1.5))
if p * log(2) / 1.5 > 1:
    print(r)
else:
    print(p)