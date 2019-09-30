H,W,N=map(int,input().split())
z={}
for _ in range(N):
    x,y=map(int,input().split())
    if z.get(x,10**6) > y:
        z[x] = y
length=1
for x in range(1,H):
    if z.get(x+1,10**6) <= length:
        print(x)
        exit()
    elif z.get(x+1,10**6) == length+1:
        continue
    length+=1
print(H)