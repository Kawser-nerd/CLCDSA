def solve(ns,cs):
	l = []
	for i in range(len(ns)):
		if ns[i] == 0:
			cs[i] -= 1
		for _ in range(cs[i]):
			l.append(ns[i])
	return ' '.join(map(str, log_bag(l)))
	
def log_bag(bag, so_far=[0], acc=[]):
	if len(bag) == 0:
		return acc

	#print 'log_bag',bag,so_far,acc
		
	for i,n in enumerate(bag):
		to_remove = [n+s for s in so_far]
		sub_bag = []
		bag_i=0
		rem_i=0
		
		good = True
		
		while 1:
			if rem_i==len(to_remove):
				break
			if bag_i==len(bag) or bag[bag_i] > to_remove[rem_i]:
				good = False
				break
			if bag[bag_i] == to_remove[rem_i]:
				bag_i += 1
				rem_i += 1
			else:
				sub_bag.append(bag[bag_i])
				bag_i += 1
		
		while bag_i < len(bag):
			sub_bag.append(bag[bag_i])
			bag_i += 1
		
		#print to_remove,good
		
		if good:
			sub_so_far = sorted(so_far + to_remove)
			sub_acc = acc + [n]
			sub = log_bag(sub_bag, sub_so_far, sub_acc)
			if sub != None:
				return sub
		

n_cases = input()
for i in range(1,n_cases+1):
	input()
	ns = map(int, raw_input().split(' '))
	cs = map(int, raw_input().split(' '))
	solution = solve(ns,cs)
	print "Case #%d: %s" % (i,solution)