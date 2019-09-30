#!/usr/bin/env python3
import sys
from pprint import pprint


# Digit DP
def solve(N: int):
    s = str(N + 1)
    n = len(s)
    # dp[idx][smaller][started][3][5][7]
    dp = [[[[[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(n + 1)]
    dp[0][0][0][0][0][0] = 1
    for i in range(0, n):
        for smaller in range(2):
            for started in range(2):
                for i1 in range(2):
                    for i2 in range(2):
                        for i3 in range(2):
                            for nex in [0, 3, 5, 7]:
                                if not smaller and nex > int(s[i]):
                                    #print(i, nex)
                                    continue
                                if started and nex == 0:
                                    continue
                                #print(i, smaller, started, i1, i2, i3)
                                #print(dp[0][0][0][0][0][0])
                                #if not (smaller | nex < int(s[i])):
                                #    print(' --- ')
                                #    print(i, smaller, started, i1, i2, i3, nex, int(s[i]), nex < int(s[i]))
                                #    print(smaller, nex < int(s[i]))
                                #    print(smaller or nex < int(s[i]))
                                #    print(' --- ')

                                #dp[i + 1][smaller | nex < int(s[i])][started | nex > 0][i1 | nex == 3][i2 | nex == 5][i3 | nex == 7] += \
                                dp[i + 1][smaller or nex < int(s[i])][started or nex > 0][i1 or nex == 3][i2 or nex == 5][i3 or nex == 7] += \
                                    dp[i][smaller][started][i1][i2][i3]
        #pprint(dp[i])
        #print()
    ret = dp[n][1][1][1][1][1]
    #pprint(dp[n])
    print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)

if __name__ == '__main__':
    main()