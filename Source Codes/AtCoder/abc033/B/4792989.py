n = int(input())
x = [list(map(str,input().split())) for i in range(n)]
p = 0
for i in range(n):
    p += int(x[i][1])
for i in range(n):
    if int(x[i][1])>p//2:
        print(x[i][0])
        exit()
else:
    print("atcoder")