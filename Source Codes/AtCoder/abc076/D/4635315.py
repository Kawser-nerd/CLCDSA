import sys
from itertools import accumulate

def main():
    input = sys.stdin.readline
    N = int(input())
    T = list(map(int, input().split()))
    V_limit = list(map(int, input().split()))

    V = []
    for i in range(N):
        V += [V_limit[i] for _ in range(2 * T[i])]

    for i in range(len(V)-1):
        V[i] = min(V[i], V[i+1])

    V = [0] + V
    V[-1] = 0

    for i in range(len(V)-1):
        V[i+1] = min(V[i] + 0.5, V[i+1])

    for i in range(len(V)-1, 0, -1):
        V[i-1] = min(V[i] + 0.5, V[i-1])

    ans = 0
    for i in range(len(V)-1):
        ans += 0.25 * (V[i] + V[i+1])
    
    print(ans)


if __name__ == '__main__':
    main()