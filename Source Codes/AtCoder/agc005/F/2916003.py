import sys
import numpy as np

def power_table(MOD, w, size):
    w_table = [0] * size
    w_table[0] = 1
    for i in range(1, size):
        w_table[i] = w_table[i - 1] * w % MOD
    return w_table

def numpy_ntt(MOD, w_table, data, scale=None):
    data_np = np.array(data)
    size = len(data)
    step = 1
    while step < size:
        batch_size = size // (step * 2)
        data_np = data_np.reshape((step * 2, -1))
        w1 = w_table[0:size // 2:batch_size].reshape((step, -1)).repeat(batch_size, axis=1)
        w2 = w_table[size // 2:size:batch_size].reshape((step, -1)).repeat(batch_size, axis=1)
        odd = data_np[0::2]
        even = data_np[1::2]
        sub1 = (odd + even * w1) % MOD
        sub2 = (odd + even * w2) % MOD
        data_np = np.concatenate((sub1, sub2))
        step *= 2
    if scale is not None:
        data_np = data_np * scale % MOD
    return data_np.flatten()

def read_data():
    int_list = [int(s) for s in sys.stdin.read().split()]

    n = int_list[0]

    graph = [[] for _ in range(n)]
    for i in range(0, (n - 1) * 2, 2):
        a = int_list[i + 1] - 1
        b = int_list[i + 2] - 1
        graph[a].append(b)
        graph[b].append(a)

    size_table = [1] * n

    ret = 0
    stack = [-1, 0, 0]

    while True:
        node = stack[-1]
        index = stack[-2]
        size_table[node] += ret
        if index < len(graph[node]):
            dtr = graph[node][index]
            stack[-2] += 1
            if dtr != stack[-3]:
                stack.extend((0, dtr))
            ret = 0
        else:
            del stack[-2:]
            if len(stack) <= 1: break
            ret = size_table[node]

    g = [0] * n
    for s in size_table:
        if s != n:
            g[s - 1] += 1
            g[n - s - 1] += 1
    return (n, g)


def solve():
    MOD = 924844033

    def pow_mod(a, n):
        ret = 1
        while n != 0:
            if n % 2 == 1: ret = ret * a % MOD
            a = a * a % MOD
            n //= 2
        return ret

    n, answer = read_data()

    fac = [0] * (n + 1)
    fac[0] = 1
    for i in range(1, n + 1):
        fac[i] = fac[i - 1] * i % MOD

    ifac = [0] * (n + 1)
    ifac[n] = pow_mod(fac[n], MOD - 2)
    for i in range(n, 0, -1):
        ifac[i - 1] = ifac[i] * i % MOD

    def comb(x, y):
        return fac[x] * ifac[y] % MOD * ifac[x - y] % MOD

    for i in range(n):
        answer[i] = answer[i] * fac[i + 1] % MOD
    answer.reverse()

    ntt_size = 1
    while ntt_size <= n * 2: ntt_size *= 2

    w_table = power_table(MOD, pow_mod(5, (MOD - 1) // ntt_size), ntt_size)

    np_w_table = np.array(w_table)
    ifac_ntt = numpy_ntt(MOD, np_w_table, ifac[:n] + [0] * (ntt_size - n))
    answer_ntt = numpy_ntt(MOD, np_w_table, answer + [0] * (ntt_size - n))

    answer_ntt = answer_ntt * ifac_ntt % MOD

    for i in range(1, ntt_size // 2):
        w_table[i], w_table[ntt_size - i] = w_table[ntt_size - i], w_table[i]
    answer = numpy_ntt(MOD, np.array(w_table), answer_ntt, pow_mod(ntt_size, MOD - 2)).tolist()

    for i in range(1, n + 1):
        a = n * comb(n, i) % MOD
        b = answer[n - i] * ifac[i] % MOD
        print((a - b + MOD) % MOD)

solve()