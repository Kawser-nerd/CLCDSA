#!/usr/bin/env python3

def main():
    A = input()

    n = len(A)

    next_i = []
    ct = [n] * 26
    orda = ord("a")
    for i in range(n - 1, -1, -1):
        ct[ord(A[i]) - orda] = i
        next_i.append(ct.copy())

    next_i.reverse()

    dp = [0] * (n + 1)
    dp[n] = 1
    j = -1
    for i in range(n - 1, -1, -1):
        ct = next_i[i]
        if max(ct) < n:
            j = i
            break
        else:
            dp[i] = 1

    if j == -1:
        ct = next_i[0]
        for c in range(26):
            if ct[c] == n:
                print(chr(orda + c))
                return

    rt = [0] * n
    for i in range(j, -1, -1):
        ct = next_i[i]
        min_c = 0
        min_v = dp[ct[0] + 1]
        for c in range(1, 26):
            v = dp[ct[c] + 1]
            if v < min_v:
                min_c = c
                min_v = v
        rt[i] = min_c
        dp[i] = min_v + 1


    r = ''
    i = 0
    while i < n:
        if dp[i] == 1:
            for c in range(26):
                if not chr(orda + c) in A[i:]:
                    r += chr(orda + c)
                    break
            break
        r += chr(orda + rt[i])
        i = next_i[i][rt[i]] + 1


    print(r)


if __name__ == '__main__':
    main()