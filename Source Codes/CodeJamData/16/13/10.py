# Mutual BFFs may make a bigger circle
# 2 1 4 3 can fit all four
# If we start with A, then B, then C != A, we just go until we get somebody already in the circle

# Two cases: its a cycle or it's not
# If it's a cycle, we can count those quickly, O(N^2) is good enough
# Otherwise, we have some mutual pairs a <-> b and tails that point into them

def chain(b,x):
	sz = 1
	for i in range(len(b)):
		if b[i] == x and b[x] != i:
			sz = max(sz, 1+chain(b,i))
	return sz

def solve(b):
	# Find max cycle
	mx = 0
	for i in range(len(b)):
		seen = [0]*len(b)
		seen[i] = 1
		cur = i
		while seen[b[cur]] == 0:
			seen[b[cur]] = seen[cur] + 1
			cur = b[cur]
		mx = max(seen[cur] - seen[b[cur]] + 1, mx)
	# Find component sizes
	c = 0
	for i in range(len(b)):
		if b[b[i]] == i:
			c += chain(b,i) + chain(b,b[i])
	return max(c/2, mx)

T_max = int(raw_input())
for T in range(T_max):
	N = int(raw_input())
	bffs = map(int, raw_input().split(" "))
	for i in range(N):
		bffs[i] -= 1
	out = "Case #" + str(T+1) + ": " + str(solve(bffs))
	print out
	
	

