#B??
K,S=map(int,input().split())
count=0
for y in range(K+1):
    x=0
    for x in range(K+1):
        z=S-(x+y)
        if z <= K and z >= 0:
            count+=1
print(count)