H, W, h, w =list(map(int,input().split()))
INF = 10**10
mat = [[1000 for _ in range(H)] for _ in range(W)]

val =-h*w*1000+ 999
for h_new in range(h-1,H,h):
    for w_new in range(w-1,W,w):
        mat[w_new][h_new] = val

if (sum(sum(mat[j][i] for i in range(H)) for j in range(W)))< 0:
    print("No")
else:
    print("Yes")
    for i in range(H):
        for j in range(W):
            print(mat[j][i], end =" ")
        print("")