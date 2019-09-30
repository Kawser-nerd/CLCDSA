from collections import deque
n = int(input())
a,b = map(int,input().split())
a = a-1
b = b-1
m = int(input())

tree = [[] for i in range(n)]

for i in range(m):
  tmp1,tmp2 = map(int,input().split())
  tree[tmp1-1].append(tmp2-1)
  tree[tmp2-1].append(tmp1-1)

visited = [0]*n
counted = [0]*n
visited[a] = 1
counted[a] = 1

q = deque()
q.append(a)
q.append(tree[a])
q.append("|")
q.append("|")
count = 2

while q:
  comefrom = q.popleft()
  goto = q.popleft()
  
  if comefrom == "|":
    count += 1
    q.append("|")
    q.append("|")
    if counted[b]>=1:
      print(counted[b]%1000000007)
      exit()
    continue

  for goto_ in goto :
    if visited[goto_] == 0 or visited[goto_] == count :
      if visited[goto_] == 0:
        q.append(goto_)
        q.append(tree[goto_])
      counted[goto_] += counted[comefrom]
      visited[goto_] = count