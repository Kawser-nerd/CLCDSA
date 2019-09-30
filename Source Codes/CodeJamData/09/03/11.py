#!/usr/bin/env python3

from sys import stdin, stdout, stderr

phrase = "welcome to code jam"

def solve_case(text):
    ans = [[0] * (len(text) + 1) for i in range(len(phrase) + 1)]
    for i in range(len(text) + 1):
        ans[-1][i] = 1
    for i, c in reversed(list(enumerate(phrase))):
        for j, d in reversed(list(enumerate(text))):
            if d == c:
                ans[i][j] = ans[i][j + 1] + ans[i + 1][j + 1]
            else:
                ans[i][j] = ans[i][j + 1]
    return ans[0][0]

def read_case():
    return input()

def print_case(i, ans):
    s = "Case #%d: %s" % (i, ("%4d" % (ans % 10000)).replace(" ", "0"))
    print(s)

def main():
    for i in range(1, int(input()) + 1):
        print_case(i, solve_case(read_case()))

if __name__ == "__main__":
    main()

