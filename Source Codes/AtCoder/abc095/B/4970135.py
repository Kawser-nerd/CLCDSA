N, X = map(int, input().split())
mList=[]
for i in range(N):
    mList.append(int(input()))
sumM = sum(mList)
minM = min(mList)
print(N + (X - sumM)//minM)