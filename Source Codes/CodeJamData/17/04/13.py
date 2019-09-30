import sys
import numpy as np
import heapq
from gurobipy import *

def solve(n,models):

	m = Model("fashion")
	m.setParam("OutputFlag",0)

	xVar = {}
	pVar = {}
	oVar = {}

	for c in range(1,n+1):
		for r in range(1,n+1):
			xVar[(r,c)] = m.addVar(0.0,1.0,1,GRB.BINARY, str((r,c)))
			pVar[(r,c)] = m.addVar(0.0,1.0,1,GRB.BINARY, str((r,c)))
			oVar[(r,c)] = m.addVar(0.0,1.0,2,GRB.BINARY, str((r,c)))
	

	m.update()

	# constraints
	for c in range(1,n+1):
		m.addConstr(quicksum(oVar[(r,c)] + xVar[(r,c)] for r in range(1,n+1)) <= 1)

	for r in range(1,n+1):
		m.addConstr(quicksum(oVar[(r,c)] + xVar[(r,c)] for c in range(1,n+1)) <= 1)

	for c in range(1,n+1):
		for r in range(1,n+1):
			m.addConstr(oVar[(r,c)] + pVar[(r,c)] + xVar[(r,c)] <= 1)


	for d in range(0,n):
		m.addConstr(quicksum(oVar[(o,o+d)] + pVar[(o,o+d)] for o in range(1,n+1-d)) <= 1)
		m.addConstr(quicksum(oVar[(o,o-d)] + pVar[(o,o-d)] for o in range(d+1,n+1)) <= 1)
		m.addConstr(quicksum(oVar[(o,n-o+1 + d)] + pVar[(o,n-o+1 + d)] for o in range(d+1,n+1)) <= 1)
		m.addConstr(quicksum(oVar[(o,n-o+1 - d)] + pVar[(o,n-o+1 - d)] for o in range(1,n-d+1)) <= 1)

	for mod in models:
		if mod[0] == '+':
			m.addConstr(pVar[(mod[1],mod[2])] + oVar[(mod[1],mod[2])] >= 1)
		if mod[0] == 'x':
			m.addConstr(xVar[(mod[1],mod[2])] + oVar[(mod[1],mod[2])] >= 1)
		if mod[0] == 'o':
			m.addConstr(oVar[(mod[1],mod[2])] == 1)

	m.modelSense = GRB.MAXIMIZE
	m.optimize()

	modelsOut = []
	obj = 0

	for c in range(1,n+1):
		for r in range(1,n+1):
			val = pVar[(r,c)].getAttr('X')
			if val > 0.1:
				modelsOut.append(('+',r,c))
				obj = obj + 1
			val = xVar[(r,c)].getAttr('X')
			if val > 0.1:
				modelsOut.append(('x',r,c))
				obj = obj + 1
			val = oVar[(r,c)].getAttr('X')
			if val > 0.1:
				modelsOut.append(('o',r,c))
				obj = obj + 2
	
	modelsOut = set(modelsOut)
	models = set(models)

	modelsOut = modelsOut - models

	return [obj, len(modelsOut), modelsOut]


t = int(raw_input())
for i in range(1, t + 1):
  n, m = [int(s) for s in raw_input().split(" ")]
  models = []
  for j in range(1, m + 1):
  	t, r, c = [s for s in raw_input().split(" ")]
  	models.append((t,int(r),int(c)))

  result = solve(n, models)

  print("Case #{}: {} {}".format(i, result[0], result[1]))
  for el in result[2]:
  	print("{} {} {}".format(el[0], el[1], el[2]))
