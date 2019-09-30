#!/usr/bin/env python3

def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    A.sort()
    B.sort()
    C.sort()
    S = [0]

    s = 0
    i = 0
    for b in B:
        while i < N:
            if b <= A[i]:
                break
            i += 1
        s += i
        S.append(s)

    t = 0
    i = 0
    for c in C:
        while i < N:
            if c <= B[i]:
                break
            i += 1
        t += S[i]


    print(t)


if __name__ == '__main__':
    main()