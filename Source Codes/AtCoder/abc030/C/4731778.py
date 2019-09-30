import bisect
n,m=map(int, input().split())
x,y=map(int, input().split())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
time=0
count=0
while True:
    try:
        time=a[bisect.bisect_left(a,time)]
        time+=x
        time=b[bisect.bisect_left(b,time)]
        time+=y
        count+=1
    except:
        break
print(count)