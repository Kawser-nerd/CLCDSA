# coding: utf-8

II = lambda: int(input())
MI = lambda: map(int, input().split())
MIL = lambda: list(MI())
MIS = lambda: input().split()


def main():
    N = II()
    A = [0] + MIL() + [0]
    d = [abs(A[i] - A[i + 1]) for i in range(N + 1)]
    cost = sum(d)

    for i in range(1, N + 1):
        print(cost - (d[i] + d[i-1]) + abs(A[i-1] - A[i+1]))


if __name__ == "__main__":
    main()