N = int(input())
K = int(input())

a = 1
for i in range(N):
    if a < K:
        a *= 2
    else:
        a += K
print(a)