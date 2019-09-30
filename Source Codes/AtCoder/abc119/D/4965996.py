#!/usr/bin/env python3
import sys


def solve(N: int, M: int, Q: int, s: "List[int]", t: "List[int]", x: "List[int]"):

    def binary_search(ary, val):
        n = len(ary)
        l = -1
        r = n
        while r - l > 1:
            mid = (l + r) // 2
            if ary[mid] >= val:
                r = mid
            else:
                l = mid
        if l == -1:
            return [ary[0]]
        if r == n:
            return [ary[n - 1]]
        return [ary[l], ary[r]]

    for q in x:
        ret = float('inf')
        a_pos = binary_search(s, q)
        b_pos = binary_search(t, q)
        for a in a_pos:
            for b in b_pos:
                ret = min(ret, abs(a - q) + abs(b - a))
                ret = min(ret, abs(b - q) + abs(a - b))
        print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    A = int(next(tokens))  # type: int
    B = int(next(tokens))  # type: int
    Q = int(next(tokens))  # type: int
    s = [ int(next(tokens)) for _ in range(A) ]  # type: "List[int]"
    t = [ int(next(tokens)) for _ in range(B) ]  # type: "List[int]"
    x = [ int(next(tokens)) for _ in range(Q) ]  # type: "List[int]"
    solve(A, B, Q, s, t, x)

if __name__ == '__main__':
    main()