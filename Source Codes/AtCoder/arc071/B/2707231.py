mod = 10 ** 9 + 7

def sum_subarrays(A):
    N = len(A)
    S = [0]
    for a in A:
        S.append(S[-1] + a)
        S[-1] %= mod
    return sum((2 * i - N - 1) * s % mod for i, s in enumerate(S)) % mod

N, M = map(int, input().split())
X = [0] + list(map(int, input().split()))
Y = [0] + list(map(int, input().split()))
diff_X = [X[i + 1] - X[i] for i in range(N)]
diff_Y = [Y[i + 1] - Y[i] for i in range(M)]
print(sum_subarrays(diff_X) * sum_subarrays(diff_Y) % mod)