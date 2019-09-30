#!/usr/bin/env python3

def main():
    n, r = map(int, input().split())
    s = list(input())

    rightmost = -1
    for i, c in enumerate(s):
        if c == ".":
            rightmost = i

    if rightmost == -1:
        print(0)
    else:
        count = 0
        at = 0
        for i in range(1000):
            if is_finished(s):
                break
            if s[at] == ".":
                update_s(s, at, r)
                count += 1
            else:
                at += 1
        move = max(0, rightmost - r + 1)
        print(move + count)

def is_finished(s):
    return "." not in s

def update_s(s, i, r):
    n = len(s)
    for j in range(i, i + r):
        if j < n:
            s[j] = "o"

main()