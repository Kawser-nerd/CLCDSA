#! /usr/bin/env python

vowels = ['a', 'e', 'i', 'o', 'u']

T = int(input())
for TT in range(1, T + 1):
    s, n = input().split()
    n = int(n)
    ans = 0
    current = 0
    count = 0
    length = len(s)
    for i in range(0, length):
        if s[i] in vowels:
            count = 0
        else:
            count += 1
        if count == n:
            count -= 1
            ans += (i - n + 2 - current) * (length - i)
            current = i - n + 2

    print("Case #" + str(TT) + ": " + str(ans))
