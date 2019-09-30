import sys
sys.setrecursionlimit(100000)

def puts(s):
	print(s,end='')

def direction(x,y):
	if x>0:
		return "E"
	if x<0:
		return "W"
	if y>0:
		return "N"
	if y<0:
		return "S"

def movesReq(x,y):
	mandis = abs(x)+abs(y)
	dis = 0
	moves = 0
	while mandis>dis or dis%2!=mandis%2:
		moves += 1
		dis += moves
	return moves

def solutions(x,y,num):
	if num==0 and x==0 and y==0:
		yield ""
	elif movesReq(x,y)<=num:
		for d,xp,yp in [("E",x-num,y),("W",x+num,y),("S",x,y+num),("N",x,y-num)]:
			for s in solutions(xp,yp,num-1):
				yield s+d

def solve(case):
	x, y = map(int,input().split())
	num = movesReq(x,y)
	for s in solutions(x,y,num):
		print(s)
		break

for case in range(1,1+int(input())):
	puts("Case #"+str(case)+": ")
	solve(case)