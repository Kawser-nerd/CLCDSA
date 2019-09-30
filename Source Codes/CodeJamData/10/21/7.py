
class Tree:
  def __init__(self):
    self.dirs=[]
    self.next=[]

T=input()
for t in range(T):
  sum=0
  root=Tree()
  n,m=map(int,raw_input().split())
  for i in range(n):
    line=raw_input().split("/")[1:]
    tmp=root
    for j in line:
      if j not in tmp.dirs:
        tmp.dirs.append(j)
        tmp.next.append(Tree())
      tmp=tmp.next[tmp.dirs.index(j)]
  for i in range(m):
    line=raw_input().split("/")[1:]
    tmp=root
    for j in line:
      if j not in tmp.dirs:
        sum+=1
        tmp.dirs.append(j)
        tmp.next.append(Tree())
      tmp=tmp.next[tmp.dirs.index(j)]
  print "Case #%d: %d"%(t+1,sum)

