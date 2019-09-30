#!/usr/bin/env python3

def main():
    n = int(input())
    keta = len(str(n))
    li = []
    for i in range(1, 9 * keta + 1):
        x = n - i
        if f(x) == i:
            li.append(x)
    li.sort()
    print(len(li))
    for x in li:
        print(x)

def f(x):
    if x < 0:
        return -1
    sx = str(x)
    res = 0
    for c in sx:
        res += int(c)
    return res

main()