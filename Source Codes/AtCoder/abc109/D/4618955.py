H,W = (int(x) for x in input().split())

a_mat = []
for _ in range(H):
    a_mat.append([int(x) for x in input().split()])

out_op = []
for h in range(H):
    for w in range(W):
        if h%2 == 0:
            wd = w
            if w == W-1:
                next_pos = (h+1, wd)
            else:
                next_pos = (h, wd+1)
        else:
            wd = W-1-w
            if w == W-1:
                next_pos = (h+1, wd)
            else:
                next_pos = (h, wd-1)
        if h == H-1 and w == W-1:
            break
        if a_mat[h][wd] % 2 == 1:
            a_mat[next_pos[0]][next_pos[1]] += 1
            out_op.append((h, wd, next_pos[0], next_pos[1]))

print(len(out_op))
for y,x,yn,xn in out_op:
    print(y+1,x+1,yn+1,xn+1)