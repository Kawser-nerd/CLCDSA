#!/usr/bin/env python3

def main():
    N = int(input())
    A = list(map(int, input().split()))

    A.sort(reverse = True)
    e = []
    i = 0
    while i < N - 1:
        if A[i] == A[i + 1]:
            e.append(A[i])
            if len(e) == 2:
                print(e[0] * e[1])
                return
            i += 2
        else:
            i += 1


    print(0)


if __name__ == '__main__':
    main()