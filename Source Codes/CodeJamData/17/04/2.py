from __future__ import print_function
import sys
from sys import stdin


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)



from sys import stdin

def ln(f=int):
	return list(map(f,stdin.readline().strip().split()))

from pulp import *
from itertools import product
from collections import defaultdict


solver = pulp.GUROBI(msg=0)

T, = ln()
for test in range(T):
	if sys.argv[1:][0] == "0":
		do = test <= 33
	elif sys.argv[1:][0] == "1":
		do = test > 33 and test <= 66
	else:
		do = test > 66
	if do:
		eprint(test)

	N,M = ln()

	if do:
		prob = LpProblem("problem1", LpMaximize)

		var_plus = pulp.LpVariable.dicts('model_+', product(range(N),range(N)), 
		                            lowBound = 0,
		                            upBound = 1,
		                            cat = pulp.LpInteger)
		var_x = pulp.LpVariable.dicts('model_x', product(range(N),range(N)), 
		                            lowBound = 0,
		                            upBound = 1,
		                            cat = pulp.LpInteger)
		var_o = pulp.LpVariable.dicts('model_o', product(range(N),range(N)), 
		                            lowBound = 0,
		                            upBound = 1,
		                            cat = pulp.LpInteger)

		

		prob += lpSum(list(var_plus.values())) + lpSum(list(var_x.values())) + 2*lpSum(list(var_o.values()))
		for (r,c) in product(range(N),range(N)):
			prob += var_plus[(r,c)] + var_x[(r,c)] + var_o[(r,c)] <= 1

		for r in range(N):
			prob += lpSum( [ var_x[(r,c)] for c in range(N) ]) + lpSum( [ var_o[(r,c)] for c in range(N) ]) <= 1
		for c in range(N):
			prob += lpSum( [ var_x[(r,c)] for r in range(N) ]) + lpSum( [ var_o[(r,c)] for r in range(N) ]) <= 1

		d1 = defaultdict(list)
		for (r,c) in product(range(N),range(N)):
			d1[r+c].append((r,c))

		d2 = defaultdict(list)
		for (r,c) in product(range(N),range(N)):
			d2[r-c].append((r,c))

		for (_,xs) in d1.items():
			prob += lpSum( [ var_plus[(r,c)] for (r,c) in xs ]) + lpSum( [ var_o[(r,c)] for (r,c) in xs ]) <= 1
		for (_,xs) in d2.items():
			prob += lpSum( [ var_plus[(r,c)] for (r,c) in xs ]) + lpSum( [ var_o[(r,c)] for (r,c) in xs ]) <= 1



	ins = set()
	for i in range(M):
		s,r,c  = ln(str)
		if do:
			r = int(r)-1
			c = int(c)-1
			if s=="+":
				prob += var_plus[(r,c)] + var_o[(r,c)] >= 1
			elif s=="x":
				prob += var_x[(r,c)] + var_o[(r,c)] >= 1
			elif s=="o":
				prob += var_o[(r,c)] >= 1
			else:
				assert False
			ins.add( (s,r+1,c+1) )


	if do:
		prob.setSolver(solver)
		prob.solver.buildSolverModel(prob)
		prob.solve()


		# The status of the solution is printed to the screen
		# print("Status:", LpStatus[prob.status])
		# # Each of the variables is printed with it's resolved optimum value
		# for v in prob.variables():
		#     print(v.name, "=", v.varValue)


		res = set()
		for ((r,c),v) in var_plus.items():
			if v.varValue == 1:
				res.add( ("+" , r+1 , (c+1)) )
		for ((r,c),v) in var_x.items():
			if v.varValue == 1:
				res.add( ("x" , (r+1) , (c+1)) )
		for ((r,c),v) in var_o.items():
			if v.varValue == 1:
				res.add( ("o" , (r+1) , (c+1)) )

		rs = list(res-ins)
		print("Case #{}: {} {}".format(test+1,int(pulp.value(prob.objective)),len(rs)))
		for pr in rs:
			print( " ".join([str(vi) for vi in pr]) )





	# from collections import defaultdict

	# V,E,R,C,X = [int(x) for x in input().strip().split()]
	# vid_size = [int(x) for x in input().strip().split()]

	# vid_req = defaultdict(list) # vi -> [req]
	# ep_cache_delay = {} 
	# ep_datacenter_delay = [-1]*E

	# req_delay_curr = {} # req -> singleton delay. init to data centre time
	# cache_size_curr = [0]*C # 

	# ep_caches = defaultdict(list)

	# from pulp import *
	# prob = LpProblem("cacheproblem", LpMinimize)
	# cost = None

	# from itertools import product
	# var_vid_in_cache = pulp.LpVariable.dicts('vid_in_cache_', product(range(V),range(C)), 
	#                             lowBound = 0,
	#                             upBound = 1,
	#                             cat = pulp.LpInteger)
	# print ("0")
	# for ci in range(C):
	# 	prob += lpSum([vid_size[vi]*var_vid_in_cache[(vi,ci)] for vi in range(V)]) <= X
	# 	print (ci)

	# print ("loading endpoint descriptions")

	# for ei in range(E):
	# 	l_d, K  = [int(x) for x in input().strip().split()]
	# 	ep_datacenter_delay[ei] = l_d
	# 	for index in range(K):
	# 		ci, delay = [int(x) for x in input().strip().split()]
	# 		ep_cache_delay[(ei,ci)] = delay
	# 		ep_caches[ei].append(ci)

	# print ("adding request costs")
	# for ri in range(R):
	# 	(vi,ei,n) = [int(x) for x in input().strip().split()]

	# 	srcs = ['datacenter'] + ep_caches[ei]
	# 	var_ep_use_src = pulp.LpVariable.dicts(str(ri)+'_usesrc', srcs, 
	#                             lowBound = 0,
	#                             upBound = 1,
	#                             cat = pulp.LpInteger)

	# 	prob += sum(var_ep_use_src.values()) == 1

	# 	for ci in ep_caches[ei]:
	# 		prob += var_ep_use_src[ci] <= var_vid_in_cache[(vi,ci)]

	# 	req_cost = (n*ep_datacenter_delay[ei])*var_ep_use_src['datacenter']
	# 	req_cost += lpSum([(n*ep_cache_delay[(ei,ci)])*var_ep_use_src[ci] for ci in ep_caches[ei]])
	# 	if cost != None:
	# 		cost += req_cost
	# 	else:
	# 		cost = req_cost
	# 	print (ri)

	# prob += cost


	# print ("Built problem")


	# # from pulp import *
	# # prob = LpProblem("chicken", LpMinimize)
	# # x = LpVariable("x", 0 , None, LpInteger) # 0 is the lower bound;
	# #                                   # "None" means no upper bound;
	# # y = LpVariable("y", 0 , None, LpInteger)
	# # z = LpVariable("z", 0 , None, LpInteger)

	# # prob += x+y+z == 100, "constraint 1"
	# # prob += x*3+y*2+z*0.5 == 100, "constraint 2"

	# prob.writeLP("problem3.lp")
	# print("writ")
	# print(str(len(prob.variables())) + " variables")
	# print(str(len(prob.constraints)) + " constraints")

	# prob.solve()


	# # The status of the solution is printed to the screen
	# print("Status:", LpStatus[prob.status])
	# # # Each of the variables is printed with it's resolved optimum value
	# # for v in prob.variables():
	# #     print(v.name, "=", v.varValue)


	# res = defaultdict(list)
	# for ((vi,ci),v) in var_vid_in_cache.items():
	# 	if v.varValue == 1:
	# 		res[ci].append(vi)

	# print(len(res.items()))
	# for (ci,vis) in res.items():
	# 	print( str(ci) + " " + " ".join([str(vi) for vi in vis]) )





	# from collections import defaultdict

	# V,E,R,C,X = [int(x) for x in input().strip().split()]

	# INF= float("inf")

	# vid_size = [int(x) for x in input().strip().split()]

	# vid_req = defaultdict(list) # vi -> [req]
	# ep_cache_delay = {} 
	# ep_datacenter_delay = [-1]*E

	# req_delay_curr = {} # req -> singleton delay. init to data centre time
	# cache_size_curr = [0]*C # 

	# for ei in range(E):
	# 	l_d, K  = [int(x) for x in input().strip().split()]
	# 	ep_datacenter_delay[ei] = l_d
	# 	for index in range(K):
	# 		ci, delay = [int(x) for x in input().strip().split()]
	# 		ep_cache_delay[(ei,ci)] = delay

	# for ri in range(R):
	# 	(vi,ei,n) = [int(x) for x in input().strip().split()]
	# 	req = (vi,ei,n)
	# 	vid_req[vi].append(req)
	# 	req_delay_curr[req] = ep_datacenter_delay[ei]


	# res = defaultdict(list)

	# from queue import PriorityQueue
	# pq = PriorityQueue()

	# # add all (cache,video) pairs to queue with score = INF
	# for ci in range(C):
	# 	for vi in range(V):
	# 		pq.put((-INF,(ci,vi)))

	# # keep removing highest priority, update score, insert back - or use
	# while not pq.empty():

	# 	# get proposal
	# 	(score_old,proposal) = pq.get() # negate remember!
	# 	score_old *= -1
	# 	(ci,vi) = proposal

	# 	if cache_size_curr[ci] + vid_size[vi] <= X:
	# 		#check score
	# 		score = 0
	# 		for req in vid_req[vi]: # requests in form (req,total delay sum)
	# 			(_,ei,n) = req
	# 			if (ei,ci) in ep_cache_delay:
	# 				# calculate delay improvmeent
	# 				improvement = max(0, req_delay_curr[req] - ep_cache_delay[(ei,ci)])
	# 				score += improvement*n
	# 		score /= float(vid_size[vi])

	# 		if score == score_old: # valid
	# 			res[ci].append(vi)

	# 			cache_size_curr[ci] += vid_size[vi]

	# 			for req in vid_req[vi]: # update request delays
	# 				(_,ei,n) = req
	# 				if (ei,ci) in ep_cache_delay:
	# 					req_delay_curr[req]  = min( req_delay_curr[req], ep_cache_delay[(ei,ci)] )

	# 		else:
	# 			# put back
	# 			pq.put((-score,proposal))

	# print(len(res.items()))
	# for (ci,vis) in res.items():
	# 	print( str(ci) + " " + " ".join([str(vi) for vi in vis]) )

