import collections
from collections import deque
n,m = map(int,input().split())
ko = deque([])
for i in range(n):
  a= deque(map(int,input().split()))
  ko.append(a)
dai = float("inf")
for j in range(m):
  san = []
  for i in range(n):
    san.append(ko[i][0])
  c = collections.Counter(san)
  to = c.most_common()[0]
  dai = min(to[1],dai)
  ira = to[0]
  for i in range(n):
    ko[i].remove(ira)
print(dai)