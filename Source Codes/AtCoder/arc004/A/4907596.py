N = int(input())
x=[];y=[]
for _ in range(N):
    x1 ,y1 = map(int, input().split())
    x.append(x1); y.append(y1)
ans = 0.0
for i in range(N):
    for j in range(N):
        if ans < ((x[i]-x[j])**2 + (y[i]-y[j])**2)**0.5:
            ans = ((x[i]-x[j])**2 + (y[i]-y[j])**2)**0.5
print(ans)