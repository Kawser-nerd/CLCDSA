from decimal import Decimal
N, va, vb, L = map(int, input().split())
t = 0
for i in range(N):
    t = Decimal(L/va)
    L = Decimal(vb*t)
print('%04.12f' % L)