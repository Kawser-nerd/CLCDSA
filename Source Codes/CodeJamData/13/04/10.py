import sys

class Chest:
	def __init__(self, name, numbers):
		self.name = name
		self.key_type = numbers[0]
		number_of_keys_inside = numbers[1]
		self.keys_inside = numbers[2:]
		assert len(self.keys_inside) == number_of_keys_inside

class Problem:
	def __init__(self, keys, chests):
		self.initial_keys = keys
		self.chests = chests
		
	def is_feasible(self, keys, chests_opened):
		#try to filter out clearly impossible problems
		
		#keys that we have or will have in the future:
		keys_in_hand = keys[:]
		for i,chest in enumerate(self.chests):
			if i not in chests_opened:
				keys_in_hand.extend(chest.keys_inside)
		
		#keys that are still needed:
		for i,chest in enumerate(self.chests):
			if i not in chests_opened:
				key = chest.key_type
				if key not in keys_in_hand:
					return False
				keys_in_hand.remove(key)
		return True
	
	def is_feasible2(self, keys, chests_opened):
		covered = [False] * len(self.chests)
		for i in chests_opened:
			covered[i] = True
		
		def open(key):
			for i, chest in enumerate(self.chests):
				if covered[i]:
					continue
				if chest.key_type == key:
					covered[i] = True
					for key_inside in chest.keys_inside:
						open(key_inside)
		
		for k in keys:
			open(k)
		return all(covered)
	
	def get_solution(self, keys, chests_opened):
		if len(chests_opened) == len(self.chests):
			return chests_opened
		
		if not self.is_feasible(keys, chests_opened):
			return None
		if not self.is_feasible2(keys, chests_opened):
			return None
		
		for i in range(len(self.chests)):
			if i in chests_opened:
				continue
			chest = self.chests[i]
			if chest.key_type not in keys:
				continue
			
			new_keys = keys[:]
			new_keys.remove(chest.key_type)
			new_keys.extend(chest.keys_inside)
			solution = self.get_solution(new_keys, chests_opened+[i])
			if solution != None:
				return solution
			
			#no solution using this chest:
			if chest.key_type in chest.keys_inside:
				return None
		
		return None
	
	def get_first_solution(self):
		return self.get_solution(self.initial_keys, [])
	
	def translate_solution(self, solution):
		return [self.chests[i].name for i in solution]

def read_numbers():
	return map(int, raw_input().split(" "))

cases_count = input()
for case in xrange(cases_count):
	K,N = read_numbers()
	keys = read_numbers()
	chests = []
	for i in range(N):
		chests.append( Chest(i+1, read_numbers()) )
	assert len(keys) == K
	assert len(chests) == N
	print>>sys.stderr, K,N
	
	p = Problem(keys, chests)
	solution = p.get_first_solution()
	
	if solution == None:
		solution_str = "IMPOSSIBLE"
	else:
		solution = p.translate_solution(solution)
		solution_str = " ".join(map(str, solution))
	print "Case #%d: %s" % (case+1, solution_str)
