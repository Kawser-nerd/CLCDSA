H, W = map(int, input().split())
s = [input() for i in range(H)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

ans = True
for i in range(H):
    for j in range(W):
        if s[i][j] == '.':
            continue
        else:
            check = True
            for k in range(len(dx)):
                y = i+dy[k]
                x = j+dx[k]
                if x<0 or x>(W-1) or y<0 or y>(H-1):
                    continue
                else:
                    if s[y][x]=='#':
                        check = False
            if check:
                ans = False
                break
    if not ans:
        break

if ans:
    print("Yes")
else:
    print("No")