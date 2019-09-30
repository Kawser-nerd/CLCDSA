class BinaryIndexedTree:
  def __init__(self, size):
    self.data = [0] * (size+1)
    self.size = size
  
  def add(self, i, w):
    while i <= self.size:
      self.data[i] += w
      i += i & -i

  def sum(self, i):
    result = 0
    while i > 0:
      result += self.data[i]
      i -= i & -i
    return result

from bisect import bisect

N,K = map(int, input().split())

A = [int(input()) for i in range(N)]

t = 0
B = [t]
for a in A:
  t += a - K
  B.append(t)

temp = sorted(B)
C = [bisect(temp, b) for b in B]

result = 0
bit = BinaryIndexedTree(N+1)

for c in C:
  result += bit.sum(c)
  bit.add(c,1)

print(result)