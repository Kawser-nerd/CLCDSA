n = int(input())
ma = [list(input()) for i in range(n)]
for i in range(n):
    li = []
    for j in range(n):
        li+=ma[n-j-1][i]
    print("".join(li))