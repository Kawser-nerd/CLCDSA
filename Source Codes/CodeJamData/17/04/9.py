
# capacities: a dictionary whose keys are edges and values are capacities
# s: the source vertex
# t: the sink vertex
def max_flow(capacities, s, t):

	caps_by_vertex = {}
	for u,v in capacities:
		if not u in caps_by_vertex:
			caps_by_vertex[u] = {}
		caps_by_vertex[u][v] = capacities[(u,v)]
		if not v in caps_by_vertex:
			caps_by_vertex[v] = {}

	def shortest_st_path():
		cur = set([s])
		visited = set([s])
		prevs = {}
		while not t in visited:
			if len(cur) == 0:
				return None
			next = set()
			for u in cur:
				if not u in caps_by_vertex: continue
				
				for v in caps_by_vertex[u]:
					if not v in visited:
						next.add(v)
						visited.add(v)
						prevs[v] = u
			cur = next
		path = [t]
		while path[-1] != s:
			path.append(prevs[path[-1]])
		path = path[::-1]
		return path
	
	flows = {}
	while True:
		path = shortest_st_path()
		if path == None:
			break
		
		path_edges = []
		
		for i in range(len(path)-1):
			u = path[i]
			v = path[i+1]
			path_edges.append((u,v))
		
		min_cap = None
		for (u,v) in path_edges:
			cap = caps_by_vertex[u][v]
			if min_cap == None or cap < min_cap:
				min_cap = cap
		
		for (u,v) in path_edges:
			caps_by_vertex[u][v] -= min_cap
			if caps_by_vertex[u][v] == 0:
				del caps_by_vertex[u][v]
			
			if not v in caps_by_vertex:
				caps_by_vertex[v] = {}
				
			if not u in caps_by_vertex[v]:
				caps_by_vertex[v][u] = 0
			
			caps_by_vertex[v][u] += min_cap
			
			if not (u,v) in flows:
				flows[(u,v)] = 0
			flows[(u,v)] += min_cap
			if not (v,u) in flows:
				flows[(v,u)] = 0
			flows[(v,u)] -= min_cap
	
	return [(u,v,flows[(u,v)]) for (u,v) in flows if flows[(u,v)] > 0]

def maximal_bipartite_matching(edges):
	edges = [('x' + str(x),'y' + str(y)) for (x,y) in edges]

	lefts = set()
	rights = set()
	
	capacities = dict()
	
	s = 's'
	t = 't'
	
	for a,b in edges:
		capacities[(s,a)] = 1
		capacities[(a,b)] = 1
		capacities[(b,t)] = 1
	
	flow = max_flow(capacities, s, t)
	
	result = []
	for a,b,c in flow:
		assert c == 1
		if a != s and b != t:
			result.append((a,b))
		
	return [(int(x[1:]),int(y[1:])) for x,y in result]

def solve_orthogonal(locations, size):
	xs = set(x for (x,y) in locations)
	ys = set(y for (x,y) in locations)
	
	all = set(range(size))
	missing_xs = all - xs
	missing_ys = all - ys
	
	edges = [(x,y) for x in missing_xs for y in missing_ys]
	results = maximal_bipartite_matching(edges)
	return results
	
def xy_to_ij((x,y)):
	return (x+y, x-y)

def ij_to_xy((i,j)):
	return ( (i+j)/2, (i-j)/2 )
	
def is_valid((i,j), size):
	if (i+j)%2 != 0: return False
	
	x,y = ij_to_xy((i,j))
	if x < 0 or x >= size: return False
	if y < 0 or y >= size: return False
	
	return True
	
def solve_diagonal(locations, size):

	ij_locations = map(xy_to_ij, locations)
	
	i_set = set(i for (i,j) in ij_locations)
	j_set = set(j for (i,j) in ij_locations)
	
	all_is = set(range(size+size-1))
	all_js = set(range(1-size,size))
	
	missing_is = all_is - i_set
	missing_js = all_js - j_set
	
	edges = [(i,j) for i in missing_is for j in missing_js if is_valid((i,j), size)]
	
	ij_results = maximal_bipartite_matching(edges)
	xy_results = map(ij_to_xy, ij_results)
	
	return xy_results
	
def solve(models_by_location, size):
	
	orthogonal_locations = []
	diagonal_locations = []
	for (x, y) in models_by_location:
		type = models_by_location[(x,y)]
		if type in 'ox':
			orthogonal_locations.append((x,y))
		if type in 'o+':
			diagonal_locations.append((x,y))
			
	new_ortho = set(solve_orthogonal(orthogonal_locations, size))
	new_diago = set(solve_diagonal(diagonal_locations, size))
	
	promoted_locations = new_ortho | new_diago
	
	for (x,y) in new_ortho:
		if (x,y) in models_by_location:
			assert models_by_location[(x,y)] == '+'
			models_by_location[(x,y)] = 'o'
		else:
			models_by_location[(x,y)] = 'x'
		
	for (x,y) in new_diago:
		if (x,y) in models_by_location:
			assert models_by_location[(x,y)] == 'x'
			models_by_location[(x,y)] = 'o'
		else:
			models_by_location[(x,y)] = '+'
	
	return models_by_location
	
def score_solution(models_by_location):
	score = 0
	for location in models_by_location:
		type = models_by_location[location]
		score += 1
		if type == 'o':
			score += 1
	return score
	
def is_solution_valid(models_by_location, size):
	locations = list(models_by_location)

	for (x,y) in locations:
		if x < 0 or x >= size:
			# print 'Bad x:', (x,y)
			return False
		if y < 0 or y >= size:
			# print 'Bad y:', (x,y)
			return False

	for i,(x1,y1) in enumerate(locations):
		i1,j1 = xy_to_ij((x1,y1))
		
		type1 = models_by_location[(x1,y1)]
		
		for (x2,y2) in locations[i+1:]:
			i2,j2 = xy_to_ij((x2,y2))
			
			type2 = models_by_location[(x2,y2)]
			
			if (x1 == x2 or y1 == y2) and type1 != '+' and type2 != '+':
				# print 'Two non-pluses in the same row/column:',(x1,y1),(x2,y2)
				return False
			
			if (i1 == i2 or j1 == j2) and type1 != 'x' and type2 != 'x':
				# print 'Two non-x\'s in the same diagonal:',(x1,y1),(x2,y2)
				return False
	
	return True
	
def grid_to_map(grid):
	models_by_location = dict()
	for x in range(len(grid)):
		for y in range(len(grid[i])):
			type = grid[x][y]
			if type != '.':
				models_by_location[(x,y)] = type
	return models_by_location
	
	

def naive_solve(models_by_location, size, visited=None):
	if not is_solution_valid(models_by_location, size): return None

	if visited == None: visited = set()

	best_solution = dict(models_by_location)
	best_score = score_solution(models_by_location)

	for x in range(size):
		for y in range(size):
			if (x,y) in visited: continue
			
			if not (x,y) in models_by_location:
				sub_types = ['x','+','o']
			else:
				type = models_by_location[(x,y)]
				
				sub_types = []
				if type != 'o':
					sub_types.append('o')
			
			for sub_type in sub_types:
				sub_models = dict(models_by_location)
				sub_models[(x,y)] = sub_type
				sub_solution = naive_solve(sub_models, size, visited | set([(x,y)]))
				if sub_solution != None:
					sub_score = score_solution(sub_solution)
					if sub_score > best_score:
						best_score = sub_score
						best_solution = sub_solution
	
	return { loc:best_solution[loc] for loc in best_solution if best_solution[loc] != '.' }
'''
import random
for size in range(2,5):
	for i in range(100):
		models_by_location = dict()
		for x in range(size):
			for y in range(size):
				if random.randint(0,1):
					models_by_location[(x,y)] = random.choice('x+o')
		if not is_solution_valid(models_by_location, size):
			continue
		
		print 'valid - size:', size
		
		slow = naive_solve(models_by_location, size)
		fast = solve(models_by_location, size)
		
		if not is_solution_valid(slow, size):
			print 'bad slow:', slow
			assert False
			
		if not is_solution_valid(fast, size):
			print 'bad fast:', fast
			assert False
		
		slow_score = score_solution(slow)
		fast_score = score_solution(fast)
		
		if slow_score != fast_score:
			print 'slow:', slow
			print 'fast:', fast
			assert False
			
		print 'done.'

print ': )'
'''
	
case_count = input()
for case_index in range(1,case_count+1):
	size,model_count = map(int, raw_input().split(' '))
	models = []
	for _ in range(model_count):
		type,x,y = raw_input().split(' ')
		x = int(x)
		y = int(y)
		models.append((type,x,y))
	print 'Case #%d:'%case_index,
	models_by_location = { (x-1,y-1):type for (type,x,y) in models }
	
	solution = solve(dict(models_by_location), size)
	
	assert is_solution_valid(solution, size)
	
	changes = {
		loc:solution[loc]
		for loc in solution
		if (not loc in models_by_location) or models_by_location[loc] != solution[loc]
	}
	
	print score_solution(solution), len(changes)
	for (x,y) in changes:
		print changes[(x,y)],x+1,y+1
	