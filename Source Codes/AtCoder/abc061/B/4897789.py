import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    d = defaultdict(lambda: 0)
    N, M = map(int, input().split())
    for _ in range(M):
        a, b = map(int, input().split())
        d[a] += 1
        d[b] += 1

    for i in range(N):
        print(d[i+1])


if __name__ == '__main__':
    main()