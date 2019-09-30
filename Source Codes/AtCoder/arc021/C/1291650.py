# coding: utf-8
import array, bisect, collections, copy, heapq, itertools, math, random, re, string, sys, time

sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
MOD = 10 ** 9 + 7


def II(): return int(input())
def ILI(): return list(map(int, input().split()))
def IAI(LINE): return [ILI() for __ in range(LINE)]
def IDI(): return {key: value for key, value in ILI()}


def read():
    K = II()
    N = II()
    A = []
    D = []
    for __ in range(N):
        a, d = ILI()
        A.append(a)
        D.append(d)
    return (K, N, A, D)


# ???V????????????????????
def count_build(V, N, A, D):
    ret = 0
    for i in range(N):
        if V < A[i]:
            continue
        else:
            ret += ((V - A[i]) // D[i] + 1)

    return ret


def solve(K, N, A, D):
    A_max = max(A)
    D_max = max(D)

    low = 1
    hig = A_max + D_max * K
    
    # ????count?K?????value???
    while True:
        mid = (low + hig) // 2
        count = count_build(mid, N, A, D)

        if count >= K:
            hig = mid
        elif count < K:
            low = mid

        if hig - low <= 1:
            break

    last_val = low
    last_val_count = count_build(last_val, N, A, D)

    ans = 0
    for i in range(N):
        if last_val >= A[i]:
            add_count = (last_val - A[i]) // D[i]
            ans += (A[i] * 2 + add_count * D[i]) * (add_count + 1) // 2
    
    ans += (low + 1) * (K - last_val_count)

    return ans


def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()