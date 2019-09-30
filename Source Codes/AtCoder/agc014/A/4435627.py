a,b,c=map(int,input().split())
l=[]
count=0
if any([a%2==1,b%2==1,c%2==1]):
    print(0)
    exit()
while True:
    a,b,c=a//2,b//2,c//2
    a,b,c,=b+c,a+c,a+b
    count+=1
    if any([a%2==1,b%2==1,c%2==1]):
        print(count)    
        exit()
    elif [a,b,c]in l:
        print(-1)
        exit()
    l.append([a,b,c])