n, m = map(int, input().split())
A = [set([i]) for i in range(n+1)]
eve = set(range(1,n+1))
for _ in range(m):
    a, b = map(int, input().split())
    A[a].add(b)
    A[b].add(a)
for i in range(1,n+1):
  cnt = 0
  for j in eve-A[i]:
    if A[i] & A[j]:
      cnt+=1
  print(cnt)