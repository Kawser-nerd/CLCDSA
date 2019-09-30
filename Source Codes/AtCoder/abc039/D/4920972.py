# coding: utf-8
# Your code here!
import sys

h,w = [int(i) for i in input().split()]
ban = [input() for _ in range(h)]

jouge = [0,1,1,1,0,-1,-1,-1]
sayuu = [1,1,0,-1,-1,-1,0,1]

fukugen = [[0]*w for i in range(h)] # 0: black 1: white

for i in range(h):
    for j in range(w):
        if ban[i][j] == ".":
            fukugen[i][j] = 1
            for k in range(8):
                ka = jouge[k]; kb = sayuu[k]
                if 0 <= i+ka < h and 0 <= j+kb < w:
                    fukugen[i+ka][j+kb] = 1

check = [[1]*w for i in range(h)] # 0: black 1: white
for i in range(h):
    for j in range(w):
        if fukugen[i][j] == 0:
            check[i][j] = 0
            for k in range(8):
                ka = jouge[k]; kb = sayuu[k]
                if 0 <= i+ka < h and 0 <= j+kb < w:
                    check[i+ka][j+kb] = 0

ok=1
for i in range(h):
    for j in range(w):
        if check[i][j] == 1 and ban[i][j] == "#":
            ok = 0
            break
        if check[i][j] == 0 and ban[i][j] == ".":
            ok = 0
            break

#print(ban)        
#print(fukugen)
#print(check)
            
if ok==0:
    print("impossible")
    sys.exit()

print("possible")
for i in range(h):
    ans = ''.join(["#" if fukugen[i][j] ==0 else "." for j in range(w)])
    print(ans)