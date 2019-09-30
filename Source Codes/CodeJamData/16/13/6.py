_T = int(raw_input())
for _t in range(1, _T+1):
  
  N = int(raw_input())
  F = map(lambda x: int(x) - 1, raw_input().split())

  pred = [[] for i in range(N)]
  for i in range(N):
    pred[F[i]].append(i)
  tmp = [None]*N

  res = 0
  res_pairs = 0
  for root in range(N):
    if F[F[root]] == root and F[root] < root: continue
    elif F[F[root]] == root:
      n = 2
      
      for i in range(N): tmp[i] = -1
      tmp[root] = 0
      tmp[F[root]] = 0
      Q = [root]
      while len(Q) > 0:
        c = Q.pop()
        for p in pred[c]:
          if tmp[p] > -1: continue
          tmp[p] = tmp[c] + 1
          Q.append(p)
      
      n += max(tmp)
      
      for i in range(N): tmp[i] = -1
      tmp[root] = 0
      tmp[F[root]] = 0
      Q = [F[root]]
      while len(Q) > 0:
        c = Q.pop()
        for p in pred[c]:
          if tmp[p] > -1: continue
          tmp[p] = tmp[c] + 1
          Q.append(p)

      n += max(tmp)
      res_pairs += n

    else:
      for i in range(N): tmp[i] = False
      n = 1
      tmp[root] = True
      c = F[root]
      while not tmp[c]:
        n += 1
        tmp[c] = True
        c = F[c]
      if c == root: res = max(res, n)
  res = max(res, res_pairs)

  print 'Case #{}: {}'.format(_t, res)
