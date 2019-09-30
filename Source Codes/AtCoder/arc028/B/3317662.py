#!/usr/bin/env python3

def main():
    n, k = map(int, input().split())
    ages = list(map(int, input().split()))

    indices = [-1 for i in range(n)]
    for i in range(n):
        a0 = ages[i] - 1
        indices[a0] = i

    activated = [False for i in range(n)]  # Indexed by 0-based age
    cursor = n
    for i in range(n):
        a0 = ages[i] - 1
        activated[a0] = True
        if i >= k - 1:
            if cursor > a0:
                while True:
                    cursor -= 1
                    if activated[cursor]:
                        break
            print(indices[cursor] + 1)

main()