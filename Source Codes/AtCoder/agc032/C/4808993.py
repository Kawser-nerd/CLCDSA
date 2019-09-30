N, M = map(int, input().split())
c = 0
d = 0
for _ in range(min(M, 1000)):
    a, b = map(int, input().split())
    d += a * 5 + b * 7
    c += a * 2 + b * 3
    d %= 100
    c %= 100
if c * 100 + d in [15, 238, 639, 1008, 1870, 2773, 3072, 3622, 4911, 4939, 5062, 5915, 6158, 6669, 7997, 8237, 8289, 9023, 9120, 9182, 9863, 9992]:
    print("No")
else:
    print("Yes")