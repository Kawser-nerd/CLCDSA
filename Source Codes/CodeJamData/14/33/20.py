nR=int(input())
for run in range(nR):
	data=input().split()
	N=int(data[0])
	M=int(data[1])
	K=int(data[2])
	
	mini=K
	for i in range(2,N+1):
		for j in range(2,M+1):
			loss=0
			rm=0
			for k in range(min(i,j)//2):
				for m in range(5):
					if 2*k==min(i,j) and m>2:
						break
					if i*j-loss<K:
						break
					if 2*(i+j)-4-rm<mini:
						mini=2*(i+j)-4-rm
					loss+=(k+1)
					rm+=1
				if i*j-loss<K:
					break
	print("Case #"+str(run+1)+": "+str(mini))