n=int(input())
A=list(map(int,input().split()))

x=0
y=0
for a in A:
    if a%2==0:
        if a%4==0:
            x+=1
        else:
            y+=1
if x+y//2>=n//2:
    print('Yes')
else:
    print('No')