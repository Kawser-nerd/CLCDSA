n,m=map(int,input().split())
a_list=[input() for _ in range(n)]
b_list=[input() for _ in range(m)]
for i in range(n-m+1):
    for j in range(n-m+1):
        f=True
        for k in range(m):
            for l in range(m):
                if a_list[i+k][j+l]!=b_list[k][l]:
                    f=False
                    break
            if not f:
                break
        if f:
            print("Yes")
            exit()
print("No")