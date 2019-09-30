import sys
fin = sys.stdin.readline
sys.setrecursionlimit(200000)

def factorial(n, mod):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1, mod) % mod


MOD = 10**9 + 7
N = int(fin())
A_list = [int(elem) for elem in fin().split()]

fac_N = factorial(N, MOD)
inv_nums = [fac_N * pow(i, MOD - 2, MOD) % MOD for i in range(1, N + 1)]
cuml_inv_nums = [inv_nums[0]]
for inv_num in inv_nums[1:]:
    cuml_inv_nums.append((cuml_inv_nums[-1] + inv_num) % MOD)

ans = 0
for i, A in enumerate(A_list):
    ans += A * (cuml_inv_nums[i] + cuml_inv_nums[N - 1 - i] - cuml_inv_nums[0]) % MOD
    ans %= MOD

print(ans)