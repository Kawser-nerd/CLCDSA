A, B = map(int, input().split())
tmp = A
ansFlg = True
ans = 1
while ansFlg:
    if A >= B:
        print(ans)
        break
    else:
        A += tmp
        ans += 1