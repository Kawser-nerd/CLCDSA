x,y=(int(i)for i in input().split("/"))
e,g=0,2*x//y
for i in [g,g+1]:
    if (i*x)%y==0 and i:
        print(i,i*(i+1)//2-i*x//y)
    else:
        e+=1
else:
    if e==2:
        print("Impossible")