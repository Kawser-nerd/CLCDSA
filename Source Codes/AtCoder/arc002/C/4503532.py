from itertools import product

N = int(input())
cs = input()

ss = list(map(''.join, product('ABXY', repeat=2)))

ans = N
for L, R in product(ss, repeat=2):
    c2s = cs.replace(L, 'L').replace(R, 'R')
    ans = min(ans, len(c2s))

print(ans)