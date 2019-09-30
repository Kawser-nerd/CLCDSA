n = int(input())
x = [[int(i) for i in input().split()] for i in range(n)]
y,rate = [[0 for i in range(100001)] for i in range(3)],[0 for i in range(100001)]
for i in x: y[i[1]-1][i[0]] += 1
for i in range(1,100001): rate[i] = rate[i-1]+y[0][i]+y[1][i]+y[2][i]
for i in x:
	a,b = rate[i[0]-1]+y[i[1]%3][i[0]],y[i[1]-1][i[0]]-1
	print(a,n-a-b-1,b)