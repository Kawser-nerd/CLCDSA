#!/usr/bin/env python3
import sys

def ln(n: int):
    return pow(2,n+1) - 3

def pn(n: int):
    return pow(2,n) - 1

def calc(N: int, X: int):
    if N == 0:
        return 0
    if N == 1:
        return 1
    n1 = ln(N - 1)
    if X == 1:
        return 0
    elif X <= 1 + n1:
        return calc(N-1,X-1)
    elif X == 2 + n1:
        return 1 + calc(N-1,X-1)
    elif X <= 2 + 2*n1:
        return 1 + pn(N-1) + calc(N-1,X-2-n1)
    else:
        return 1 + pn(N-1)*2

def solve(N: int, X: int):
    print(calc(N + 1,X))
    return


# Generated by 1.1.4 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    X = int(next(tokens))  # type: int
    solve(N, X)

if __name__ == '__main__':
    main()