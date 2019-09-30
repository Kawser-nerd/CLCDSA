h,w = (int(i) for i in input().split())
s = [input() for i in range(h)]

arr = [["." for i in range(w)] for j in range(h)] 

for y in range(h):
    for x in range(w):
        flg = True
        for dx in range(max(0,x-1), min(w,x+2)):
            for dy in range(max(0,y-1), min(h,y+2)):
                if s[dy][dx] == ".":
                    flg = False

        if flg:
            arr[y][x] = "#"

flg = True
for y in range(h):
    for x in range(w):
        if s[y][x] == ".":
            continue

        flg_l = True
        for dx in range(max(0,x-1), min(w,x+2)):
            for dy in range(max(0,y-1), min(h,y+2)):
                if arr[dy][dx] == "#":
                    flg_l = False

        if flg_l:
            flg = False

if flg:
    print("possible")
    for x in arr:
        print("".join(x))
else:
    print("impossible")