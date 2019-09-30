# https://atcoder.jp/contests/abc103/tasks/abc103_c

import itertools
from collections import Counter
import bisect

def main():
    N = int(input())
    A = list(map(int, input().split()))
    ans = sum([a - 1 for a in A])
    print(ans)


if __name__ == '__main__':
    main()