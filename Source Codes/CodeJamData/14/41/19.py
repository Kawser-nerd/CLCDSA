Z = int(raw_input())
for z in range(Z):
  n, X = map(int,raw_input().split())
  S = map(int,raw_input().split())
  S = sorted(S)
  count = 0
  i = 0
  j = len(S) - 1
  while i <= j:
    count += 1
    if i == j:
      break
    else:
      if S[i] + S[j] <= X:
        i += 1
        j -= 1
      else:
        j -= 1
  print "Case #%d: %d" % (z+1, count)
