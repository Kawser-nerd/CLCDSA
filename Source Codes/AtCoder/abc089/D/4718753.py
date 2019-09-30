h,w,d = map(int,input().split())

data = []

for i in range(h):
    l = list(map(int,input().split()))
    for j in range(w):
        data.append((l[j],i+1,j+1))

data.sort(key = lambda x:x[0])
#print(data)
dis = [0]*(h*w+1)

for i in range(h*w,0,-1):
    if i - d < 1:
        break
    x1,y1 = data[i-d-1][1],data[i-d-1][2]
    x2,y2 = data[i-1][1],data[i-1][2]
    '''
    if i - d == 4 and i == 6:
        print(str(x1)+str(y1))
        print(str(x2)+str(y2))
    '''
    dis[i-d] = dis[i] + abs(x1-x2)+abs(y1-y2)

#print(dis) 

q = int(input())

for _ in range(q):
    l,r = map(int,input().split())
    print(dis[l]-dis[r])