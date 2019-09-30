x,y=list(map(int,input().split()))
c=0
while(True):
    if(x<=y):
        x=x*2
        c+=1
    else:
        break

print(c)