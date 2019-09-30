# Every height appears exactly twice (per row and per column)
# Can recover the missing slip easily
# Then I just need to reconstruct the 

def recover_slip(slips):
	found = {}
	ret = []
	for s in slips:
		for h in s:
			if h not in found:
				found[h] = 0
			found[h] += 1
	for h in found:
		if found[h]%2 == 1:
			ret.append(h)
	return sorted(ret)
	
T_max = int(raw_input())
for T in range(T_max):
	out = "Case #" + str(T+1) + ": "
	N = int(raw_input())
	slips = []
	for r in range(2*N-1):
		slips.append(map(int,raw_input().split(" ")))
	out += " ".join(map(str,recover_slip(slips)))
	print out