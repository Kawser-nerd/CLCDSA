h,w = (int(i) for i in input().split())
s = [input() for i in range(h)]
mem = [[0 for i in range(w)] for i in range(h)]
def win(x,y):
	if x>=h or y>=w or s[x][y]=="#": return 1
	elif mem[x][y]: return mem[x][y]
	res = 2
	if win(x+1,y)==2 or win(x+1,y+1)==2 or win(x,y+1)==2: res = 1
	mem[x][y] = res
	return res
if win(0,0)==1: print("First")
else: print("Second")