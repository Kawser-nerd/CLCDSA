H, W = map(int, input().split())
s = []
for i in range(H):
    s.append(input())
for i in range(H):
    for j in range(W):
        if s[i][j] == "#":
            bool1 = i > 0 and s[i - 1][j] == "#"
            bool2 = i < H-1 and s[i+1][j] == "#"
            bool3 = j > 0 and s[i][j - 1] == "#"
            bool4 = j < W-1 and s[i][j + 1] == "#"
            if bool1 or bool2 or bool3 or bool4:
                continue
            else:
                print("No")
                exit()

print("Yes")