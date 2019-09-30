import sys

def main():
    input = sys.stdin.readline
    H, W, D = map(int, input().split())
    d = [0] * (H*W + 1)

    for i in range(H):
        row = list(map(int, input().split()))
        for j in range(W):
            d[row[j]] = [i, j]

    A = [0] * (H*W + 1)
    for l in range(H * W - D, 0, -1):
        a = d[l]
        b = d[l+D]
        A[l] = A[l+D] + abs(a[0] - b[0]) + abs(a[1] - b[1])

    Q = int(input())
    for _ in range(Q):
        L, R = map(int, input().split())
        print(A[L] - A[R])


if __name__ == '__main__':
    main()