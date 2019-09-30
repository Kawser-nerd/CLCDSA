from sys import stdin
input = stdin.readline

y, m, d = map(int, input().split("/"))
ans = str(y+1) + "/01/01"
flag = True
n = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
# ????????n[1] = 29
if y % 400 == 0 or (y % 100 != 0 and y % 4 == 0):
    n[1] = 29
    
for i in range(m, 13):
    if y % i == 0:
        for j in range(1, n[i-1]+1):
            if i == m and j < d:
                continue
            if y % (i*j) == 0:
                if flag:
                    flag = False
                    ans = str(y) + "/" + "{0:02d}".format(i) + "/" + "{0:02d}".format(j)
                break

print(ans)