class UnionFind():
	def __init__(self,size):
		self.table = [-1 for _ in range(size)]

	def find(self,x):
		while self.table[x] >= 0:
			x = self.table[x]
		return x

	def unite(self,x,y):
		s1 = self.find(x)
		s2 = self.find(y)
		if s1 != s2:
			if self.table[s1] != self.table[s2]:
				if self.table[s1] < self.table[s2]:
					self.table[s2] = s1
				else:
					self.table[s1] = s2
			else:
				self.table[s1] += -1
				self.table[s2] = s1
		return

	def same(self,x,y):
		return self.find(x) == self.find(y)

N = int(input())
S1 = list(input())
S2 = list(input())

uf = UnionFind(100)
for i in range(N):
	uf.unite(ord(S1[i]), ord(S2[i]))

used=set()
res = 1
for i in range(N):
	curr = 0

	# ???????????????? 1 ?? ???????? ???? 1 ??
	for d in range(ord('0'),ord('0')+10):
		if uf.same(d, ord(S1[i])) == True:
			curr = 1
			break

	# ??????????????????? 9 ????????? 10 ???
	if curr != 1:
		if i == 0:
			curr = 9
		else:
			curr = 10
		# ???????????
		uf.unite(ord(S1[i]), ord('0'))

	res *= curr

print(res)