from collections import defaultdict
N=int(input())
S=[]
for _ in range(N-1):
	S.append(int(input()))

class Graph(object):
	def __init__(self):
		self.follow = defaultdict(list)
		self.pay = defaultdict(int)
		self.follow_pay_list = defaultdict(list)

	def follow_len(self,node):
		return len(self.follow[node])

	def add_edge(self, one, two):
		self.follow[one].append(two)

	def get_follow(self,node):
		return self.follow[node]

g = Graph()
for n in range(N-1):
	g.add_edge(S[n],n+2)

def DP(g,node):
	if g.follow_len(node) == 0:
		g.pay[node] = 1
		return 1
	else:
		for follow in g.get_follow(node):
			g.follow_pay_list[node].append( DP(g,follow) )
		g.pay[node] = min(g.follow_pay_list[node]) + max(g.follow_pay_list[node]) + 1
		return g.pay[node]

print( DP(g,1) )