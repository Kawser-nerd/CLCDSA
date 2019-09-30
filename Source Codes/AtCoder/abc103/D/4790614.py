N,M = map(int, input().split())

D = {}

for _ in range(M):
  a,b = map(int, input().split())
  if not b in D.keys():
    D[b] = a
  elif a > D[b]:
    D[b] = a

th = 0
count = 0
D = sorted(D.items(), key=lambda x: x[0])
for (e,s) in D:
  if ((th < s) or (e < th)):
    th = e - 1
    #print(s,e,th)
    count += 1
print(count)