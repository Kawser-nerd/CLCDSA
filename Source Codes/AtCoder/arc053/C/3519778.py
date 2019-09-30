N=int(input())
up=[]
down=[]
for _ in range(N):
    a,b=map(int,input().split())
    if a>b: up.append((a,b))
    else: down.append((a,b))
    
temp=0
temp_max=0

down.sort(key=lambda x:x[0])
for (a,b) in down:
    temp_max=max(temp_max,temp+a)
    temp=temp+a-b
    
up.sort(key=lambda x:x[1], reverse=True)
for (a,b) in up:
    temp_max=max(temp_max,temp+a)
    temp=temp+a-b
    
print(temp_max)