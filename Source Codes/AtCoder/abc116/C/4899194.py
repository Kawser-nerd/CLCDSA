N = int(input())
H = list(map(int, input().split()))

cnt = 0
for i in range(1,101):
    flg = False
    for j in range(N):
        if H[j] >= i:
            flg = True
        elif flg:
            flg = False
            cnt += 1
    if flg:
        cnt += 1
print(cnt)