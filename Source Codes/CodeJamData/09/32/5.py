
# python 3.0





def sq(p):
	return sum([x*x for x in p])

def dist(p):
	return sq(p)**.5
	






if __name__=="__main__":
	
	T = int(input())
	
	
	for X in range(1,T+1):
		
		N = int(input())
		
		t0t = [0,0,0]
		t1t = [0,0,0]
		
		for f in range(N):
			x,y,z,vx,vy,vz = [int(w) for w in input().split()]
			
			t0t[0] += x
			t0t[1] += y
			t0t[2] += z
			
			t1t[0] += x+vx
			t1t[1] += y+vy
			t1t[2] += z+vz
		
		t0m = [float(x)/float(N) for x in t0t]
		t1m = [float(x)/float(N) for x in t1t]
		
		U = [t1m[i]-t0m[i] for i in range(3)]
		
		tmin = 0.0
		denom = sq(U)
		if denom>0:
			num = sum([-t0m[i]*U[i] for i in range(3)])
			
			tmin = num/denom
		
		if tmin<0:
			tmin = 0.0
		
		
		newp = [t0m[i]+tmin*U[i] for i in range(3)]
		dmin = dist(newp)
		
		
		print("Case #"+str(X)+": "+str(dmin)+" "+str(tmin))
	
