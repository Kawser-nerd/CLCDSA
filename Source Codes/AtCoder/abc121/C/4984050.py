from sys import stdin
import heapq
hq = []  

NM = input()
NM = NM.split()
N = int(NM[0])
M = int(NM[1])

hq = []
AB = {}
for i in range(N):
  temp = input()
  temp = temp.split()
  AB[int(temp[0])] = int(temp[1])
  heapq.heappush(hq, (int(temp[0]), int(temp[1])))

cost = 0
amount = 0
for i in range(N):
  temp = heapq.heappop(hq)
  if amount + temp[1] < M:
    amount += temp[1]
    cost += temp[0]*temp[1]
  else:
    temp1 = M - amount
    cost += temp[0]*temp1
    break
    
print(cost)