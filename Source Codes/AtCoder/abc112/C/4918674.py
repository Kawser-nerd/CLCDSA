#!/usr/bin/env python3
import sys


def solve(N: int, x: "List[int]", y: "List[int]", h: "List[int]"):
    idx = 0
    for i in range(N):
        if h[i] > 0:
            idx = i
            break
    for cx in range(101):
        for cy in range(101):
            H = h[idx] + abs(cx - x[idx]) + abs(cy - y[idx])
            found = True
            for i in range(N):
                tmp_h = max(H - abs(cx - x[i]) - abs(cy - y[i]), 0)
                if tmp_h != h[i]:
                    found = False
                    break
            if H > 0 and found:
                print(cx, cy, H)
                return
    print('error')
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    x = [int()] * (N)  # type: "List[int]" 
    y = [int()] * (N)  # type: "List[int]" 
    h = [int()] * (N)  # type: "List[int]" 
    for i in range(N):
        x[i] = int(next(tokens))
        y[i] = int(next(tokens))
        h[i] = int(next(tokens))
    solve(N, x, y, h)

if __name__ == '__main__':
    main()