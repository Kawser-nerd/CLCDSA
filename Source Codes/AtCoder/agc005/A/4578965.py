X=input()
from collections import deque
lt=deque()
r=0
ans=0
while r<len(X):
    if(X[r:r+2]=='ST'):
        ans+=2
        r+=2
        continue
    elif(len(lt)>0 and X[lt[-1]]+X[r]=='ST'):
        ans+=2
        lt.pop()
        r+=1
        continue
    if(X[r]=='S'):
        lt.append(r)
        r+=1
    else:
        r+=1
        lt.clear()

print(len(X)-ans)