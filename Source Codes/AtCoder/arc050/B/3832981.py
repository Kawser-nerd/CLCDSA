R,B=map(int,input().split())
X,Y=map(int,input().split())

def ok(k):
    x=R-k
    y=B-k
    
    return x//(X-1)+y//(Y-1)>=k

low=0
high=min(R,B)

while high-low>1:
    middle=(high+low)//2
    
    if ok(middle):
        low=middle
    else:
        high=middle
        
if ok(high):
    print(high)
    
else:
    print(low)