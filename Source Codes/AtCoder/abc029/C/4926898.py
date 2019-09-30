import itertools

N = int(input())

alp = ['a','b','c']
res = []
for p in itertools.product(alp,repeat=N):
    res.append(''.join(p))

for r in sorted(res):
    print(r)