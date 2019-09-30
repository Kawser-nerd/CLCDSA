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

from itertools import accumulate,repeat

N,K = map(int, input().split())

B = [0] + [sa-sk for sa,sk in zip(accumulate(int(input()) for _ in range(N)), accumulate(repeat(K)))]

lookup = dict(((b,i+1) for i,b in enumerate(sorted(B))))

result = 0
bit = BinaryIndexedTree(N+1)

for b in B:
  c = lookup[b]
  result += bit.sum(c)
  bit.add(c,1)

print(result)