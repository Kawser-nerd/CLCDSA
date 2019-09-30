import itertools

N, K = map(int, input().split())
Ds = list(map(int, input().split()))
NDs = list(set([i for i in range(10)]) - set(Ds))
NDs = list(map(str, NDs))

min_price = 100000
for p in itertools.product(NDs, repeat=len(str(N))):
    if p[0] == '0':
        continue
    price = int(''.join(p))
    if price < N:
        continue
    min_price = min(price, min_price)

if min_price == 100000:
    for p in itertools.product(NDs, repeat=len(str(N))+1):
        if p[0] == '0':
            continue
        price = int(''.join(p))
        min_price = min(price, min_price)

print(min_price)