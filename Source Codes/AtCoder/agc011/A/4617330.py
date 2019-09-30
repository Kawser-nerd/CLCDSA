N,C,K = map(int,input().split())
Ts = sorted([int(input()) for _ in range(N)])

#print(Ts)

ans = 0
firstFlag = True
passenger = []	#limit lastNum
for i in range(N):
	if firstFlag:
		passenger = [Ts[i] + K,C-1]
		firstFlag = False
		ans += 1
		#print("first",str(passenger),Ts[i],ans)
	
	if passenger[1] <= 0:
		#print("full",str(passenger),Ts[i],ans)
		firstFlag = True
	elif i+1 < N and passenger[0] < Ts[i+1]:
		#print("time over",str(passenger),Ts[i],ans)
		firstFlag = True
	else:
		#print("other",str(passenger),Ts[i],ans)
		passenger[1] -= 1

print(ans)