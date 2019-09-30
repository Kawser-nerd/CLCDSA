import sys

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = []
    for _ in range(N):
        a, b = map(int, input().split())
        A.append((a, b))

    A = sorted(A, key=lambda x: x[0])

    cnt = 0
    for x in A:
        cnt += x[1]
        if cnt >= K:
            return x[0]


if __name__ == '__main__':
    print(main())