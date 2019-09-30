n=int(input())
a=list(map(int, input().split()))
k=len([i for i in a if i%2==1])
y=len([i for i in a if i%4==0])
g=n-k-y
if g:
    if k<=y:print('Yes')
    else:print('No')
else:
    if k<=y+1:print('Yes')
    else:print('No')