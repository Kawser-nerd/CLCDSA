#!/usr/bin/env python3

def main():
    n = int(input())
    an = list(map(int, input().split()))
    k = len(set(an))
    res = k - 1 if k % 2 == 0 else k
    print(res)

main()