txa,tya,txb,tyb,t,v=map(int,input().split())
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    if ((x-txa)**2+(y-tya)**2)**0.5+((x-txb)**2+(y-tyb)**2)**0.5<=t*v:
        print("YES")
        exit()
print("NO")