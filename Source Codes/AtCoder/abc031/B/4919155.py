L, H = map(int, input().split())
N = int(input())

for i in range(N):
    A = int(input())
    if A > H:
        print(-1)
    elif A>=L:
        print(0)
    else:
        print(L-A)