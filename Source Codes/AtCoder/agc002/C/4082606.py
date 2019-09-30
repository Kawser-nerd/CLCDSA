N, L = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
P = "Possible"
for i in range(N-1):
  if a[i] + a[i+1] >= L:
    start = i
    break  
else:
  P = "Impossible"
print(P)

if P == "Possible":
  ans = [start]
  if start > 0:
    ans += reversed(list(range(start)))
  if start != N-2:
    ans += list(range(start+1, N-1))
  ans.reverse()
  for a in ans:
    print(a+1)