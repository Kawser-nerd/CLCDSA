# https://atcoder.jp/contests/abc105/tasks/abc105_c

import itertools
import collections
import bisect

# 1024 = 10 ** 3 == 2**10 -> 10 ** 9 == 2 ** 30

def main():
    N = int(input())
    if N == 0:
        print(0)
        exit()

    v = 2
    ans = []
    while N != 0:
        if N % v == 0:
            ans.append(0)
        else:
            N -= (v // 2)
            ans.append(1)

        v *= -2
    print(''.join(map(str, ans[::-1])))


if __name__ == '__main__':
    main()