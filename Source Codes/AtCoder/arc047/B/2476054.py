n = int(input())
li = []
lis = []
lisa = []
cou = []
touch = 0
for i in range(n):
	x,y = map(int,input().split())
	lis.append((x,y))
for x,y in lis:cou.append((x+y,x-y))
for (x,y) in cou:
    li.append(x)
    lisa.append(y)
coux,couy = max(li) - min(li),max(lisa) - min(lisa)
key = max(coux,couy)
ans = [(min(li) + key//2, min(lisa)+key//2),(min(li) + key//2, max(lisa)-key // 2),(max(li) - key//2, min(lisa)+key // 2),(max(li) - key//2, max(lisa)-key // 2)]
for x, y in [ans[0],ans[1],ans[2],ans[3]]:
	ansx,ansy = (x + y)//2,(x - y)//2
	if len(set([abs(ansx - x) + abs(ansy - y) for (x,y) in lis])) == 1:break
print(ansx,ansy)