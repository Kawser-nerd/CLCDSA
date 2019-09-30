def pow_mod(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res = (res * a) % MOD
        b >>= 1
        a = (a * a) % MOD
    return res;

MOD = 1000000007

N, A, B = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
if A == 1:
    for i in range(N):
        print(arr[i] % MOD)
    exit()

count = 0
num_max = arr[N - 1]
for i in range(B):
    if arr[0] == num_max:
        break
    count += 1
    arr[0] *= A
    arr.sort()

B -= count
for i in range(B % N):
    arr[i] *= A
arr.sort()

for i in range(N):
    arr[i] %= MOD
for i in range(N):
    arr[i] *= pow_mod(A % MOD, B // N)
for i in range(N):
    for i in range(N):
        print(arr[i] % MOD)
    exit()