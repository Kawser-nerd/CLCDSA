def run():
	E,R,N=[int(i) for i in raw_input().split()]
	v=[int(i) for i in raw_input().split()]
	F=[[0,0],[int(E),0]]
	for i in range(0,N):
		l=len(F)
		F[l-1][1]=F[l-1][1]+F[l-1][0]*v[i]
		for j in range(l-2,-1,-1):
			F[j][1]=max(F[j][1]+F[j][0]*v[i],F[j+1][1])
		for j in range(0,l):
			F[j][1]-=F[j][0]*v[i]
			F[j][0]+=R
		F=[[0,F[0][1]]]+F
		G=[]
		for j in range(0,l+1):
			if F[j][0]<E:
				G.append(F[j])
			else:
				G.append([E,(-F[j-1][0]*F[j][1]+E*F[j][1]-E*F[j-1][1]+F[j][0]*F[j-1][1])/(F[j][0]-F[j-1][0])])
				break
		F=G
	return F[0][1]

T=int(raw_input())
C=1
while C<=T:
	print "Case #"+str(C)+": "+str(run())
	C+=1
