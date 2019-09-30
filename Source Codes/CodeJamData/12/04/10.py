#!/usr/bin/env python3
import sys

def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return

ints = get_ints()

def gcd(a,b):
	if a<0: a=-a
	if b<0: b=-b
	if a>b: a,b = b,a
	while a:
		a, b = b%a, a
	return b
	
def normalize(pair):
	d = gcd(pair[0],pair[1])
	return (pair[0]//d,pair[1]//d)

def explore(direction,lookup,D): #direction = (dx,dy), 0<x<=y
	vx,vy = 0,0
	x,y = 0,0
	mx=0
	hor=1
	ver=1
	(dx,dy) = direction
	while vx*vx+vy*vy < D*D:
		if mx+dx>dy: #horizontal cross, then vertical cross
			if lookup((x+hor,y))=='#': #mirror, horizontal bounce
				hor=-hor
			else: #no mirror
				x=x+hor
			if lookup((x,y+ver))=='#': #mirror, vertical bounce
				ver=-ver
			else: #no mirror
				y=y+ver
			vx = vx+1
			vy = vy+1
			mx=mx+2*dx-2*dy
		elif mx+dx==dy: #corner
			if lookup((x+hor,y+ver)) == '#': #some mirrors
				if lookup((x+hor,y))=='#': #vertical mirror
					if lookup((x,y+ver))=='#': #corner reflection
						if (2*vx+1)**2+(2*vy+1)**2 < D*D:
							return [direction]
						else:
							return []
					else: #horizontal bounce
						hor=-hor
						y=y+ver
				elif lookup((x,y+ver))=='#': #vertical bounce
					ver=-ver
					x=x+hor
				else: #dispersion
					return []
			else: #punch through
				x=x+hor
				y=y+ver
			vx = vx+1
			vy = vy+1
			mx=mx+2*dx-2*dy
		else: #vertical cross, then maybe horizontal cross
			if lookup((x,y+ver))=='#': #mirror, vertical bounce
				ver=-ver
			else: #no mirror
				y=y+ver
			if mx+2*dx>dy: #horizontal cross
				if lookup((x+hor,y))=='#': #mirror, horizontal bounce
					hor=-hor
				else: #no mirror
					x=x+hor
				vx = vx+1
				mx=mx+2*dx-2*dy
			else:
				mx=mx+2*dx
			vy = vy+1
		if lookup((x,y))=='X' and mx == 0 and vx*vx+vy*vy <= D*D: #back to the source in time
			return [direction, (-direction[0]*hor,-direction[1]*ver)]
	return []


T = next(ints)
for t in range(T):
	H = next(ints)
	W = next(ints)
	D = next(ints)
	map = []
	checked=set()
	found=set()
	for i in range(H):
		map.append(input())
		for j in range(W):
			if map[i][j]=='X': start=(j,i)
	for y in range(1,D+1):
		for x in range(y+1):
			if x*x+y*y > D*D:
				continue
			(dx, dy) = normalize((x,y))
			#processing all 8ths of the plain
			if (dx, dy) not in checked: # 2nd 8th
				checked.add((dx, dy))
				res = explore((dx, dy),lambda poz: map[start[1]-poz[1]][start[0]+poz[0]],D)
				checked.update(res)
				found.update(res)
			if (-dx, dy) not in checked: # 3rd 8th
				checked.add((-dx, dy))
				res = explore((dx, dy),lambda poz: map[start[1]-poz[1]][start[0]-poz[0]],D)
				res = [(-pair[0],pair[1]) for pair in res]
				checked.update(res)
				found.update(res)
			if (-dx, -dy) not in checked: # 6th 8th
				checked.add((-dx, -dy))
				res = explore((dx, dy),lambda poz: map[start[1]+poz[1]][start[0]-poz[0]],D)
				res = [(-pair[0],-pair[1]) for pair in res]
				checked.update(res)
				found.update(res)
			if (dx, -dy) not in checked: # 7th 8th
				checked.add((dx, -dy))
				res = explore((dx, dy),lambda poz: map[start[1]+poz[1]][start[0]+poz[0]],D)
				res = [(pair[0],-pair[1]) for pair in res]
				checked.update(res)
				found.update(res)
			if (dy, dx) not in checked: # 1st 8th
				checked.add((dy, dx))
				res = explore((dx, dy),lambda poz: map[start[1]-poz[0]][start[0]+poz[1]],D)
				res = [(pair[1],pair[0]) for pair in res]
				checked.update(res)
				found.update(res)
			if (-dy, dx) not in checked: # 4th 8th
				checked.add((-dy, dx))
				res = explore((dx, dy),lambda poz: map[start[1]-poz[0]][start[0]-poz[1]],D)
				res = [(-pair[1],pair[0]) for pair in res]
				checked.update(res)
				found.update(res)
			if (-dy, -dx) not in checked: # 5th 8th
				checked.add((-dy, -dx))
				res = explore((dx, dy),lambda poz: map[start[1]+poz[0]][start[0]-poz[1]],D)
				res = [(-pair[1],-pair[0]) for pair in res]
				checked.update(res)
				found.update(res)
			if (dy, -dx) not in checked: # 8th 8th
				checked.add((dy, -dx))
				res = explore((dx, dy),lambda poz: map[start[1]+poz[0]][start[0]+poz[1]],D)
				res = [(pair[1],-pair[0]) for pair in res]
				checked.update(res)
				found.update(res)
	print("Case #",t+1,": ",len(found),sep='')












