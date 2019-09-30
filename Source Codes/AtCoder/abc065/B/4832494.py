import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N = int(input())
    A = [0] + [int(input()) for _ in range(N)]

    cnt = 1
    pushed = set([1])
    q = deque()
    q.append(1)
    while len(q) > 0:
        a = q.popleft()
        b = A[a]
        if b == 2:
            return cnt
        elif b in pushed:
            return -1
        else:
            pushed.add(b)
            cnt += 1
            q.append(b)


if __name__ == '__main__':
    print(main())