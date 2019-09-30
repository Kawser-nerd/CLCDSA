m, n, N = map(int, input().split())
num = N
mod = 0
while True:
    N += mod
    if N < m:
        break
    num += (N // m) * n
    mod = N % m
    N = (N // m) * n
print(num)