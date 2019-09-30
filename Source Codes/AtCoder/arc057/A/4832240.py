a,b=map(int,input().split())
c=0
if b==0:
    print(2*10**12-a)
    exit()
while a<2*10**12:
    a+=1+b*a
    c+=1
print(c)