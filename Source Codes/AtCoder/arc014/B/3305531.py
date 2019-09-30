#!/usr/bin/env python3

def main():
    n = int(input())
    words = [input() for i in range(n)]
    en = end_at_one_based(words)
    if en == 0:
        print("DRAW")
    elif en % 2 == 0:
        print("WIN")
    else:
        print("LOSE")

def end_at_one_based(words):
    se = set()
    for i, w in enumerate(words):
        if w in se:
            return i + 1
        if i > 0 and w[0] != words[i - 1][-1]:
            return i + 1
        se.add(w)
    return 0

main()