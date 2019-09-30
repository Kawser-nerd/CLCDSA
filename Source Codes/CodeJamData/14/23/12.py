from itertools import permutations
T = input()
N = 0

def legal(perm, adj):
	stack = [perm[0]]
	perm = perm[1:]
	while len(perm):
		v = perm[0]
		while len(stack) > 0 and v not in adj[stack[-1]]:
			stack = stack[:-1]
		if len(stack) == 0:
			return False
		stack.append(v)
		perm = perm[1:]
	return True



for case in range(1, T + 1):
    ans = None
    N, M = map(int, raw_input().split())
    zips = [raw_input() for i in range(N)]
    adj = [set() for i in range(N)]
    for i in range(M):
    	e = map(lambda x:int(x) - 1, raw_input().split())
    	adj[e[0]].add(e[1])
    	adj[e[1]].add(e[0])

    v = 0
    for w, z in enumerate(zips):
    	if z <= zips[v]:
    		v = w
    # print zips[v]
    for perm in permutations(range(N)):
    	if perm[0] != v:
    		continue
    	if legal(perm, adj):
    		concat = ''.join(zips[i] for i in perm)
    		# print perm, concat
    		if ans is None or concat <= ans:
    			ans = concat

    print "Case #%d:" % case, ans