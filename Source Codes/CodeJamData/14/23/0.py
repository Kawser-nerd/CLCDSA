T=int(raw_input())
for Case in xrange(T):
	N,M=map(int,raw_input().split())
	A=map(int,[raw_input() for i in xrange(N)])
	E=[[] for i in xrange(N)]
	for i in xrange(M):
		a,b=map(int,raw_input().split())
		a-=1
		b-=1
		E[a].append(b)
		E[b].append(a)
	S=A.index(min(A))

	def force(used,stack):
		if all(used):
			return ''
		if len(stack)==0:
			return -1
		r=force(used,stack[:-1])
		for i in E[stack[-1]]:
			if used[i]==0:
				t=force([int(used[j] or j==i) for j in xrange(N)],stack+[i])
				if t!=-1:
					t=str(A[i])+t
					if r==-1 or t<r:
						r=t
		return r
	
	#print 'Case #%d:'%(Case+1),str(A[S])+force([int(i==S) for i in xrange(N)],[S])
	#continue

	used=[0 for i in xrange(N)]
	used[S]=1
	def availneighbour(a):
		return sorted([(A[i],i) for i in E[a] if used[i]==0])
	stack=[[S,availneighbour(S)]]
	ret=str(A[S])
	def dfs(a):
		if used[a]==0:
			used[a]=2
		for i in E[a]:
			if used[i]==0:
				dfs(i)
	failattempt=[]
	while not all(used):
		#print 's',stack
		p=-1
		for i in xrange(len(stack)):
			if len(stack[i][1]) and (p==-1 or stack[p][1][0]>=stack[i][1][0]):
				p=i
		#print 'p',p,'r',ret
		t=stack[p][1][0][1]
		if used[t]:
			stack[p][1]=stack[p][1][1:]
			continue
		for i in xrange(p+1):
			dfs(stack[i][0])
		succ=all(used)
		for i in xrange(N):
			if used[i]==2:
				used[i]=0
		if not succ:
			failattempt.append((p,stack[p][1][0]))
			stack[p][1]=stack[p][1][1:]
			continue
		stack[p][1]=stack[p][1][1:]
		for u,v in failattempt[::-1]:
			stack[u][1]=[v]+stack[u][1]
		failattempt=[]
		while len(stack)>p+1:
			stack.pop()
		used[t]=1
		#print 't',t
		ret+=str(A[t])
		stack.append([t,availneighbour(t)])
	print 'Case #%d:'%(Case+1),ret
