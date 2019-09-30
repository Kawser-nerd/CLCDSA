import sys
write = sys.stdout.write

def valid(x, y):
    H = info[nzpoint][2] + abs(info[nzpoint][0]-x) + abs(info[nzpoint][1]-y)
    for i in range(N):
        if i == nzpoint:
            continue
        if max(0, H - abs(x-info[i][0]) - abs(y-info[i][1])) != info[i][2]:
            return False
    return True
        

def printheight(i, j):
    write(str(info[nzpoint][2] + abs(i-info[nzpoint][0]) + abs(j-info[nzpoint][1])) + "\n")

N = int(input())
info = []
nzpoint = 0
for i in range(N):
    info.append(list(map(int,input().split())))
    if info[i][2] > 0:
        nzpoint = i
#0-100?????????
for i in range(101):
    for j in range(101):
        if valid(i, j):
            write(str(i) + " " + str(j) + " ")
            printheight(i, j)
            sys.exit()