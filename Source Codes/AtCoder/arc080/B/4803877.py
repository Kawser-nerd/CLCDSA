H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))
ans = []
c = 1
for i in a:
    for j in range(i):
        ans.append(c)
    c += 1
for i in range(H):
    for j in range(W):
        if i % 2 == 0:
            print(ans[i * W + j], end = "")
        else:
            print(ans[i * W + W - 1 - j], end = "")
        if j < W - 1:
            print(" ", end = "")
        else:
            print()