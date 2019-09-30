# coding: utf-8
import array, bisect, collections, copy, heapq, itertools, math, random, re, string, sys, time
sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
MOD = 10 ** 9 + 7


def II(): return int(input())
def ILI(): return list(map(int, input().split()))
def IAI(LINE): return [ILI() for __ in range(LINE)]
def IDI(): return {key: value for key, value in ILI()}


def nCk(n, k):
    ret = 1
    if n - k < k:
        k = n - k
    for i in range(n, n - k, -1):
        ret = ret * i % MOD
    fact = [1] * (k + 1)
    for i in range(1, k + 1):
        fact[i] = fact[i - 1] * i % MOD
    return ret % MOD * pow(fact[k], MOD - 2, MOD) % MOD


def read():
    N = II()
    A = ILI()
    return N, A


def solve(N, A):
    head_num = A[0]
    count_minus = 0
    ans = 1

    for ind, a in enumerate(A):
        if a == -1:
            count_minus += 1
            continue
        else:
            if count_minus == 0:
                head_num = a
                continue
            else:
                delta = a - head_num
                num_n = delta + count_minus
                num_k = count_minus
                ans *= nCk(num_n, num_k)
                head_num = a
                count_minus = 0

    return (ans % MOD)


def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()