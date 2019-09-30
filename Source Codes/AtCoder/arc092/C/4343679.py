#!/usr/bin/env python3


def solve(n, aa):

    opa = []

    a_max = max(aa)

    if a_max <= 0:
        print(a_max)
        x = aa.index(a_max) + 1
        for i in range(n, x, -1):
            opa.append(i)
        for i in range(1, x):
            opa.append(1)
    else:
        sum0 = 0
        sum1 = 0
        for i in range(n):
            a = aa[i]
            if 0 < a:
                if i % 2 == 0:
                    sum0 += a
                else:
                    sum1 += a
        print(max(sum0, sum1))

        used = [False] * n
        i0 = 1 if sum0 < sum1 else 0
        for i in range(i0, n, 2):
            if 0 < aa[i]:
                used[i] = True

        k = n
        for i in range(n - 1, -1, -1):
            if not used[i]:
                opa.append(i + 1)
                k -= 1
            else:
                break
        j = 0
        for i in range(k):
            if not used[i]:
                opa.append(1)
                j += 1
            else:
                break

        c = 0
        for i in range(k - 1, j - 1, -1):
            if used[i]:
                c = 0
            else:
                c += 1
                if c == 3:
                    opa.append(i - j + 2)
                    k -= 2
                    c = 1

        for i in range((k - j) // 2):
            opa.append(2)


    print(len(opa))
    for v in opa:
        print(v)


def main():
    n = input()
    n = int(n)
    aa = list(map(int, input().split()))

    solve(n, aa)


if __name__ == '__main__':
    main()