#!/usr/bin/env python3

INF = 10 ** 8
MAX_T = 10 ** 6

def solve(n, lst):

    tl = []
    lst.sort()
    p = None
    for i in range(n - 1, -1, -1):
        a, b, j = lst[i]
        if p is None or b <= p:
            tl.append(a)
            p = a

    ans = [INF] * len(tl)
    k = len(tl) - 1
    p = None
    ta = tl[k]
    tb = tl[k - 1] if 0 < k else MAX_T
    for i in range(n):
        a, b, j = lst[i]
        if ta < a:
            k -= 1
            ta = tl[k]
            tb = tl[k - 1] if 0 < k else MAX_T
            p = np
        if p is None or p <= a:
            if b <= tb:
                if j < ans[k]:
                    ans[k] = j
                    np = b

    ans.reverse()

    print(len(ans))
    print(' '.join(map(str, ans)))


def main():
    n = input()
    n = int(n)
    lst = []
    for j in range(n):
        a, b = input().split()
        a = int(a)
        b = int(b)
        lst.append((a, b, j + 1))

    solve(n, lst)


if __name__ == '__main__':
    main()