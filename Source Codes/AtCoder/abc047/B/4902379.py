w, h, n = map(int, input().split())

x=[0]*n
y=[0]*n
a=[0]*n
white=[0,h,w,0]
for i in range(n):
    line = list(map(int, input().split()))
    x[i] = line[0]
    y[i] = line[1]
    a[i] = line[2]

    if a[i] == 1:
        white[0] = max(white[0],x[i])
    elif a[i] == 2:
        white[2] = min(white[2], x[i])
    elif a[i] == 3:
        white[3] = max(white[3], y[i])
    elif a[i] == 4:
        white[1] = min(white[1], y[i])

newh = (white[1] - white[3])
neww = (white[2] - white[0])
print(newh * neww if newh >=0 and neww >=0 else 0)