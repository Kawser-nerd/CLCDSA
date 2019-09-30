MOD = 1000000007

N, A, B = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
if A == 1:
    for i in range(N):
        print(arr[i] % MOD)
    exit()

count = 0
for i in range(B):
    if arr[0] * A > arr[-1]:
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
    arr[i] *= pow(A % MOD, B // N, MOD)
for i in range(N):
    for i in range(N):
        print(arr[i] % MOD)
    exit()