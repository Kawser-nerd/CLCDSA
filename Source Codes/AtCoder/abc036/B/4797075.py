n = int(input())
c = [list(input()) for i in range(n)]
for i in range(n):
    for j in range(n):
        print(c[n-j-1][i],end="")
    print()