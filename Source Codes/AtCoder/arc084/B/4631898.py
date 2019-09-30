import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N = int(input())
    q = deque([[1, 1]])
    d = {1: 1}
    while q:
        n, c = q.popleft()
        a = (n * 10) % N
        if a not in d or d[a] > c:
            d[a] = c
            q.appendleft([a, c])

        b = (n + 1) % N
        if b not in d or d[b] > c+1:
            d[b] = c + 1
            q.append([b, c+1])

    print(d[0])


if __name__ == '__main__':
    main()