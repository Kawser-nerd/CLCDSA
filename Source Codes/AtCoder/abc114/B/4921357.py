#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(S: int):
    S = str(S)
    print(min([abs(int(S[i:i+3])-753) for i in range(len(S)-2)]))
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    S = int(next(tokens))  # type: int
    solve(S)


if __name__ == '__main__':
    main()