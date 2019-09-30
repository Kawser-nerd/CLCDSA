L, H = map(int, input().split())
n = int(input())
a = [int(input()) for _ in range(n)]

for x in a:
    if x < L:
        print(L-x)
    elif L <= x <= H:
        print(0)
    else:
        print(-1)