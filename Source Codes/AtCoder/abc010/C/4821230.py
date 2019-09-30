ax,ay,bx,by,T,V=map(int,input().split())
n=int(input())
for _ in range(n):
    x,y=map(int,input().split())
    if T*V>=((x-ax)**2+(y-ay)**2)**(1/2)+((bx-x)**2+(by-y)**2)**(1/2):
        print("YES")
        exit()
print("NO")