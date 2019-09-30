from collections import defaultdict

n, k, l = map(int, input().split())

class UnionFind():
	def __init__(self, size):
		self.table = [-1 for _ in range(size)]

#	def find(self, x):
#		while self.table[x] >= 0:
#			x = self.table[x]
#		return x

	def find(self, x):
		if self.table[x] < 0:
			return x
		else:
			self.table[x] = self.find(self.table[x])
			return self.table[x]


	def union(self, x, y):
		s1 = self.find(x)
		s2 = self.find(y)
		if s1 != s2:
			if self.table[s1] > self.table[s2]:
				self.table[s2] = s1
			elif self.table[s1] < self.table[s2]:
				self.table[s1] = s2
			else:
				self.table[s1] = s2
				self.table[s2] -= 1
		return

road = UnionFind(n)
train = UnionFind(n)

for _ in range(k):
	a, b = map(int, input().split())
	road.union(a - 1, b - 1)

for _ in range(l):
	a, b = map(int, input().split())
	train.union(a - 1, b - 1)

road_root = []
for i in range(n):
	num = road.find(i)
	road_root.append(num)

train_root = []
for i in range(n):
	num = train.find(i)
	train_root.append(num)

count = defaultdict(int)
for i in range(n):
	count[road_root[i] * (10 ** 6) +  train_root[i]] += 1

ans = []
for i in range(n):
	ans.append(count[road_root[i] * (10 ** 6) +  train_root[i]])

print(*ans)