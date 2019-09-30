N,C = map(int,input().split())
d = [list(map(int,input().split())) for _ in range(C)]
c = [list(map(int,input().split())) for _ in range(N)]
c_set = [[0]*C for _ in range(3)]
for i in range(N):
    for j in range(N):
        c_set[(i+j)%3][c[i][j]-1] += 1
ans = 1e9
for c_1 in range(C):
    for c_2 in range(C):
        for c_3 in range(C):
            if c_1==c_2 or c_1==c_3 or c_2==c_3:
                continue
            c_list = [c_1,c_2,c_3]
            k = 0
            for i in range(C):
                for j in range(3):
                    k += d[i][c_list[j]-1]*c_set[j][i]
            ans = min(ans,k)
print(ans)