from math import sqrt
txa,tya,txb,tyb,t,v=map(int,input().split())
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    if sqrt((x-txa)**2+(y-tya)**2)+sqrt((x-txb)**2+(y-tyb)**2)<=t*v:
        print("YES")
        break
else:
    print("NO")