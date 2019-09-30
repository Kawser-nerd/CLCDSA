def deep(s,v):
    if(s==n):
        return v==0
    for i in range(k):
        if deep(s+1,v^t[s][i]):
            return True
    return False
    
n,k = map(int,input().split())
t = [list(map(int,input().split())) for i in range(n)]
if(deep(0,0)):
    print("Found")
else:
    print("Nothing")