#!/usr/bin/env python3

from sys import stdin, stdout, stderr

def solve_case(case):
    L, D, N, words, pattern = case
    words = set(words)
    i = 0
    j = 0
    while i < len(pattern):
        if pattern[i] == "(":
            end = pattern.find(")", i)
            options = pattern[i + 1: end]
            i = end + 1
        else:
            options = pattern[i]
            i += 1
        remove = set()
        for word in words:
            if word[j] not in options:
                remove.add(word)
        for word in remove:
            words.remove(word)
        j += 1
    return len(words)

def print_case(i, ans):
    s = "Case #%d: %s" % (i, ans)
    print(s)

def main():
    L, D, N = map(int, input().split())
    words = [input() for i in range(D)]
    for i in range(1, N + 1):
        pattern = input()
        print_case(i, solve_case((L, D, N, words, pattern)))

if __name__ == "__main__":
    main()

