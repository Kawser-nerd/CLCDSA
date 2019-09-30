import sys
sys.setrecursionlimit(10000)

def solve(n,d,S0,As,Cs,Rs,M0,Am,Cm,Rm):
	employees = []
	managers = []
	salaries = []
	
	employees.append([])
	managers.append(None)
	salaries.append(S0)
	
	S = S0
	M = M0
	
	for i in range(1,n):
		S = (S*As+Cs)%Rs
		M = (M*Am+Cm)%Rm
	
		employees.append([])
		managers.append(M%i)
		employees[M%i].append(i)
		salaries.append(S)
	
	#print
	#print employees
	#print managers
	#print salaries
	#print
	
	return best(employees, salaries, 0, d)
		
def best(employees, salaries, root, d):
	by_salary = sorted(range(len(salaries)), key=lambda i:salaries[i])
	
	low_cost = None
	
	for i in range(len(by_salary)):
		j = i+1
		# TODO: binary search
		while j<len(by_salary) and salaries[by_salary[j]]-salaries[by_salary[i]]<=d:
			j += 1
		removed = set()
		#print
		for k in range(i):
			#print by_salary[k],
			add_to_removed(employees, by_salary[k], removed)
		for k in range(j,len(by_salary)):
			#print by_salary[k],
			add_to_removed(employees, by_salary[k], removed)
		#print
		if low_cost == None or len(removed) < low_cost:
			low_cost = len(removed)
		#print i,j,removed
		
		if j == len(by_salary):
			break
			
	return len(employees) - low_cost
		
def add_to_removed(employees, m, removed):
	if m in removed:
		return
	removed.add(m)
	for e in employees[m]:
		add_to_removed(employees, e, removed)
		
n_cases = input()
for i in range(1,n_cases+1):
	n,d = map(int,raw_input().split(' '))
	S0,As,Cs,Rs = map(int,raw_input().split(' '))
	M0,Am,Cm,Rm = map(int,raw_input().split(' '))
	solution = solve(n,d,S0,As,Cs,Rs,M0,Am,Cm,Rm)
	print "Case #%d: %s" % (i,solution)