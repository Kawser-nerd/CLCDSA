a, b = 2, 1
N = int(input())
for _ in range(N):
    a, b = b, a+b
print(a)