N, L = map(int, input().split())
s = [input() for _ in range(L)]
K = input().find("o") // 2

def f(l, k):
    if l == 0:
        return k
    else:
        if k > 0 and s[l - 1][2 * k - 1] == "-":
            k_next = k - 1
        elif k < N - 1 and s[l - 1][2 * k + 1] == "-":
            k_next = k + 1
        else:
            k_next = k
        return f(l - 1, k_next)

print(f(L, K) + 1)