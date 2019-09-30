N,M = map(int,input().split())
L = []
des = [0]
ans = 0
for i in range(M):
  L.append(list(map(int,input().split())))
L = sorted(L,key = lambda x:x[1])
for i in range(M):
  if des[len(des)-1] < L[i][0]:
    ans += 1
    des.append(L[i][1]-1)
print(ans)