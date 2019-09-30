R,C,K= map(int, input().split())
S=[]
sum=[[0 for i in range(505)] for j in range(505)]
RR=[[0 for i in range(505)] for j in range(505)]
LL=[[0 for i in range(505)] for j in range(505)]

def getL(y,x,s):
	return LL[y+1+(s-1)][x+1-(s-1)]-LL[y+1-1][x+1+1]

def getR(y,x,s):
	return RR[y+1+(s-1)][x+1+(s-1)]-RR[y+1-1][x+1-1]
	

for y in range(R):
	S.append(list(input()))
	for x in range(C):
		sum[y+1][x+1]=sum[y+1][x]+(S[y][x]=='o')
		RR[y+1][x+1]=RR[y][x+1-1]+(S[y][x]=='o')
		LL[y+1][x+1]=LL[y][x+1+1]+(S[y][x]=='o')

ret=0
ss=1+4*(K-1)*K/2

for y in range(R):
	if y < K-1 or y+K-1 >= R:
		continue
	
	st = 0
	for x in range(K-1,C-(K-1)):
		if x == K-1:
			for i in range(-(K-1),K):
				st += sum[y+i+1][x+(K-1-abs(i))+1]-sum[y+i+1][x-(K-1-abs(i))]
		else:
			st += getR(y-(K-1),x,K-1)
			st += getL(y,x+(K-1),K)
			
		if st==ss:
			ret += 1
		st -= getL(y-(K-1),x,K-1)
		st -= getR(y,x-(K-1),K)

print(ret)