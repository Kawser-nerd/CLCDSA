import math

eps = 0.0000001
def Solve(H, W, D, c):
	#find x
	angles = []
	W = W - 2
	H = H - 2
	found = False
	y = -0.5
	for line in c:
		x = -0.5
		for char in line:
			if char == "X":
				found = True
				break
			x = x + 1
		if found:
			break
		y = y + 1
	#print "coord: ",x,y
	mx = x
	my = y
	co = 0
	for xcopy in range(-50,50):
		for ycopy in range(-50,50):
			if (xcopy == 0 and ycopy == 0):
				continue
			if xcopy % 2 != 0:
				mx = (xcopy+1) * (W) -  x
			else:
				mx = xcopy * (W) + x
			if ycopy % 2 != 0:
				my = (ycopy+1) * (H) - y
			else:
				my = ycopy * (H) + y
			dist = math.sqrt((mx-x)**2 + (my-y)**2)
			if dist <= D:
				a = 0
				# if (abs(mx-x) == 0):
				# 	print "zero!"
				# 	if my-y > 0:
				# 		a = 44
				# 	else:
				# 		a = 22
				# else:
				a = math.atan2((my-y),(mx-x))
				#print a
				if not hasAngle(a, angles):
					co = co + 1 
					angles.append(a)
				#print "indist!",mx,my,dist
	return co

def hasAngle(a, angles):
	for an in angles:
		if abs(an - a ) < eps:
			return True
	return False



f = open('d.in')
T = int(f.readline())
for t in range(T):
    H, W, D = map(int, f.readline().split())
    c = []
    for x in range(H):
    	c.append(f.readline())

    #print freq
    result = Solve(H, W, D, c)
    print "Case #%d: %s" % (t+1, result)
