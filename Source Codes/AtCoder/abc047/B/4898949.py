w,h,n = map(int,input().split())
lo = [0,0]
hi = [w,h]
for i in range(n):
    a,b,x = map(int,input().split())
    if x == 1:
        if a >= lo[0]:
            lo[0] = a
    if x == 2:
        if a <= hi[0]:
            hi[0] = a

    if x == 3:
        if b >= lo[1]:
            lo[1] = b

    if x == 4:
        if b <= hi[1]:
            hi[1] = b
if hi[0] >= lo[0] and hi[1] >= lo[1]:
    print( (hi[0] - lo[0])*(hi[1] - lo[1]) )
else:
    print(0)