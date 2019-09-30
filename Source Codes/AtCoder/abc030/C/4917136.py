import bisect
n,m=[int(i) for i in input().split()]
x,y=[int(i) for i in input().split()]
a=sorted([int(i) for i in input().split()])
b=sorted([int(i) for i in input().split()])
airport=0
now=a[0]
cnt=0
while True:
    if airport==1:
        cnt+=1
    if airport==0:
        try:
            now=b[bisect.bisect_left(b,now+x)]
        except:
            break
        airport=1
    else:
        try:
            now=a[bisect.bisect_left(a,now+y)]
        except:
            break
        airport=0
print(cnt)