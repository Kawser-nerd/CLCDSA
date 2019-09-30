a,b,c,d,e,f=map(int,input().split())
for i in range(int(input())):
    x,y=map(int,input().split())
    if (abs(x-a)**2+abs(y-b)**2)**0.5+(abs(x-c)**2+abs(y-d)**2)**0.5<=e*f:
        print("YES")
        break
else:
    print("NO")