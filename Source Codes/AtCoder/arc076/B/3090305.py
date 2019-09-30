import heapq
import sys
sys.setrecursionlimit(10 ** 7)

class UnionFind():
	def __init__(self, size):
		self.table = [-1 for _ in range(size)]
		self.count = 0

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

			self.count += 1
			return True
		return False

n = int(input())
x = []
y = []
for i in range(n):
	a, b = map(int, input().split())
	x.append([i, a])
	y.append([i, b])

vx = sorted(x, key=lambda x: x[1])
vy = sorted(y, key=lambda x: x[1])

edges = []
uf = UnionFind(n)

for i in range(n - 1):
	if vx[i][1] == vx[i + 1][1]:
		uf.union(vx[i][0], vx[i + 1][0])
	else:
		heapq.heappush(edges, (vx[i + 1][1] - vx[i][1], vx[i][0], vx[i + 1][0]))

	if vy[i][1] == vy[i + 1][1]:
		uf.union(vy[i][0], vy[i + 1][0])
	else:
		heapq.heappush(edges, (vy[i + 1][1] - vy[i][1], vy[i][0], vy[i + 1][0]))


#edges = sorted(edges, key=lambda x: x[2], reverse=True)
#print(edges)

ans = 0

while edges != []:
	e = heapq.heappop(edges)
	if uf.union(e[1], e[2]):
		ans += e[0]
	if uf.count == n - 1:
		break

print(ans)