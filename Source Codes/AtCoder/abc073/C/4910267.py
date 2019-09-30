# https://atcoder.jp/contests/abc073/tasks/abc073_c

import itertools
import collections
import bisect

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    c = collections.Counter(A)

    ans = 0
    for pair in c.items():
        if pair[1] % 2 == 1:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()