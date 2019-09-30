n = int(input())
s = [input() for i in range(n)]

cnt_r = 0
cnt_b = 0

for color in s:
    cnt_r += color.count("R")
    cnt_b += color.count("B")
if cnt_r > cnt_b:
    print("TAKAHASHI")
elif cnt_r < cnt_b:
    print("AOKI")
else:
    print("DRAW")