# https://atcoder.jp/contests/agc019/tasks/agc019_a

import itertools
import collections
import bisect
import sys
input = sys.stdin.readline

def main():
    Q, H, S, D = map(int, input().split())
    N = int(input())
    half = min(Q * 2, H)
    one = min(half * 2, S)
    two = min(one * 2, D)
    print(two * (N // 2) + one * (N % 2))

if __name__ == '__main__':
    main()