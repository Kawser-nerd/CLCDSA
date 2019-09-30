#UnionFind???
class UnionFind:
 
  def __init__(self,n):
    self.par =  [-1 for _ in range(n)]
 
  # x?????
  def root(self, x):
    if self.par[x] < 0:
      return x
    else:
      self.par[x] = self.root(self.par[x])
      return self.par[x]
  
  # x?y????????
  def merge(self, x, y):
    x = self.root(x)
    y = self.root(y)
    if x != y:
      if self.par[x] > self.par[y]:
        x, y = y, x
      self.par[x] += self.par[y]
      self.par[y] = x
  
  # x,y?????????????????:True??????:False?
  def is_same(self, x, y):
    return self.root(x) == self.root(y)
 
  # x?????????????
  def get_size(self, x):
    return -self.par[self.root(x)]

import sys
input = sys.stdin.readline

ans = []
ans_append = ans.append

n,m = map(int,input().split())
info = [tuple(map(int,input().split())) for i in range(m)]
q = int(input())
query = [tuple([i]+list(map(int,input().split()))) for i in range(q)]

from operator import itemgetter

info = sorted(info,key=itemgetter(2),reverse = True)
query = sorted(query,key=itemgetter(2),reverse = True)

info.append((-1,-1,-1))
uf = UnionFind(n+1)

#print(info)
#print(query)

cnt_info = 0
for i,man,year in query:
  while year < info[cnt_info][2] :
    uf.merge(info[cnt_info][0], info[cnt_info][1])
    cnt_info += 1
  ans_append((i,uf.get_size(man)))

ans = sorted(ans)
for i in range(q):
  print(ans[i][1])