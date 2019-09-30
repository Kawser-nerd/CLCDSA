n = int(input())
t = list(map(int,input().split()))
m = int(input())
px = []
for i in range(m):
  p,x = map(int,input().split())
  px.append([p,x])
for i in range(m):
    time = 0
    for j in range(n):
        if j+1 == px[i][0]:
            time += px[i][1]
        else:
            time += t[j]
    print(time)