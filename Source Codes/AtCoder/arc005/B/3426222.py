x,y,w=input().split(" ")
x,y=int(x)-1,int(y)-1
l=[input() for _ in [0]*9]

ma={"R":(1,0),"L":(-1,0),"U":(0,-1),"D":(0,1),"RU":(1,-1),"RD":(1,1),"LU":(-1,-1),"LD":(-1,1)}
tx,ty=ma[w]

res=""
for i in range(4):
	res+=l[y][x]
	y+=ty;x+=tx
	if x<0:
		x=1;tx=-tx
	elif x>8:
		x=7;tx=-tx
	if y<0:
		y=1;ty=-ty
	elif y>8:
		y=7;ty=-ty
print(res)