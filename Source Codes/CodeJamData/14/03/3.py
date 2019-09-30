def main():
  f = open('C.in', 'r')
  T = int (f.readline())

  for t in range(1, T+1):
    print 'Case #' + str(t) + ':'
    R, C, M = map(int, f.readline().split())
    free = R*C - M
    if free == 0:
      print 'Impossible'
    elif R == 1 or C == 1:
      print1(R, C, M)
    elif free in [2, 3, 5, 7]:
      print 'Impossible'
    elif R == 2 or C == 2:
      if (free % 2 == 0):
        print2(R, C, M)
      else:
        if (R == 2 and C == 2) or (free == 1):
          printGeneral(R, C, M)
        else:
          print 'Impossible'
    else:
      printGeneral(R, C, M)

def print1(R, C, M):
  free = R*C - M
  ans = [(['.'] * free) + (['*'] * M)]
  ans[0][0] = 'c'
  if (C == 1):
    ans = transpose(ans)
  printMap(ans)

def print2(R, C, M):
  free = R*C - M
  ans = [(['.'] * (free / 2)) + (['*'] * (M / 2)),
          (['.'] * (free / 2)) + (['*'] * (M / 2))]
  ans[0][0] = 'c'
  if (C == 2):
    ans = transpose(ans)
  printMap(ans)

def printGeneral(R, C, M):
  if (M == 0):
    ans = [['.'] * C for i in range(R)]
    ans[0][0] = 'c'
    printMap(ans)
    return
  free = R*C - M
  if (free == 1):
    ans = [['*'] * C for i in range(R)]
    ans[0][0] = 'c'
    printMap(ans)
    return
  fullLines = free / C
  if (fullLines < 2):
    if (free % 2 == 0):
      print2(2, C, 2 * C - free)
      printMap([['*'] * C for i in range(R - 2)])
    else:
      print2(2, C, 2 * C - free + 3)
      ans = [['*'] * C for i in range(R - 2)]
      ans[0][0] = '.'
      ans[0][1] = '.'
      ans[0][2] = '.'
      printMap(ans)
  else:
    rem = free - fullLines * C
    ans = [['.'] * C for i in range(fullLines)]
    ans[0][0] = 'c'
    if rem == 1:
      ans[-1][-1] = '*'
      rem += 1
      if (fullLines == 2):
        ans[-2][-1] = '*'
        rem += 1
    ans.append(['.'] * rem + ['*'] * (C - rem))
    for i in range(fullLines + 1, R):
      ans.append(['*'] * C)
    printMap(ans)

def printMap(m):
  for line in m:
    print ''.join(line)

def transpose(array):
  return [list(i) for i in zip(*array)]

if __name__ == "__main__":
    main()
