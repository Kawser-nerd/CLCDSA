r = raw_input

def solve():
  N, K = map(int, r().split())
  if K > 2 ** (N-2):
    return 'IMPOSSIBLE'

  grid = [[0 for i in range(N)] for j in range(N)]
  for i in range(1, N):
    for j in range(i + 1, N):
      grid[i][j] = 1

  for i in range(1, N):
    exp = max(N - 2 - i, 0)
    if K >= 2 ** exp:
      grid[0][i] = 1
      K -= 2 ** exp
  return '\n'.join(['POSSIBLE'] + map(lambda row: ''.join(map(str, row)), grid))

T = int(r())
for t in range(1, T + 1):
  print 'Case #%d: %s' % (t, solve())
