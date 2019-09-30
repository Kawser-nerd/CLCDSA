h,w = map(int,input().split())
ans = [["#" for i in range(w+2)] for i in range(h+2)]

a = [input() for i in range(h)]

for i in range(h):
    for j in range(w):
        ans[i+1][j+1] = a[i][j]

for i in range(h+2):
    for j in range(w+2):
        print(ans[i][j],end="")
    print()