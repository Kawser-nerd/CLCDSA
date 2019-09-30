
def BT(t):
	if memo[t]!=-1:
		return memo[t]
	
	if t==(1<<N)-1:
		memo[t] = []
		return []
		
	k = [0]*201
	for x in IK:
		k[x] += 1
	for i in range(N):
		if (t>>i&1)==1:
			k[T[i]] -= 1
			for x in K[i]:
				k[x] += 1
	for i in range(N):
		if (t>>i&1)==0 and k[T[i]]>0:
			a = BT(t|1<<i)
			if a!=0:
				memo[t] = [i+1]+a
				return [i+1]+a
	memo[t] = 0
	return 0

for test in range(input()):
	K,N = map(int,raw_input().split())
	IK = map(int,raw_input().split())
	T = [0]*N
	K = [[]]*N
	for i in range(N):
		t = map(int,raw_input().split())
		T[i] = t[0]
		K[i] = t[2:]
	
	memo = [-1]*(1<<N)
	
	a = BT(0)
	if a==0:
		ans = "IMPOSSIBLE"
	else:
		ans = " ".join(str(x) for x in a)
	
	print "Case #%s: %s"%(test+1,ans)

