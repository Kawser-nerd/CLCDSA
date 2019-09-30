C = int(input())
lm = 0
wm = 0
dm = 0
for i in range(C):
    lwd = sorted(map(int,input().split()))
    lm = max(lm,lwd[0])
    wm = max(wm,lwd[1])
    dm = max(dm,lwd[2])
print(lm*wm*dm)