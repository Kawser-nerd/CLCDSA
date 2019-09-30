N = int(input())
xList=[]
yList=[]
for i in range(N):
    x, y = map(int, input().split())
    xList.append(x)
    yList.append(y)
lenMax=0
for i in range(1, N):
    for j in range(i):
        l = (xList[i] - xList[j]) * (xList[i] - xList[j]) + (yList[i] - yList[j]) * (yList[i] - yList[j])
        if l > lenMax:
            lenMax =l
print(lenMax**(0.5))