L, H = map(int, input().split())
N = int(input())
l = [int(input()) for _ in range(N)]

for i in l:
    if i > H:
        print("-1")
    else:
        print(max(0, L - i))