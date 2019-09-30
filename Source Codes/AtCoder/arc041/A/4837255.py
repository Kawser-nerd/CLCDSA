x,y = map(int,input().split())
k = int(input())
if k >= x+y:
    print(y)
elif k >= y:
    print(2*y+x-k)
else:
    print(x+k)