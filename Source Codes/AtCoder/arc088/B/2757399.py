#!/usr/bin/env python3

def main():
    s = input()
    n = len(s)
    chs = changes(s, n)

    res = n
    for c in chs:
        di = max(c, n - c)
        res = min(res, di)

    print(res)

def changes(s, n):
    res = []
    for i in range(1, n):
        if s[i - 1] != s[i]:
            res.append(i)
    return res

main()