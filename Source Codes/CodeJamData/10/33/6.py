import psyco

T = int(raw_input())

for case in xrange(1, T+1):
  M, N = map(int, raw_input().split())

  used = [[False]*M for i in xrange(N)]
  board = [[False]*M for i in xrange(N)]

  for y in xrange(M):
    row = raw_input().strip()
    for i in xrange(N/4):
      temp = int(row[i], 16)
      for j in xrange(3, -1, -1):
        board[i*4+j][y] = (temp&1)==1
        temp /= 2

  #print case, "::"
  #for y in xrange(M):
  #  for x in xrange(N):
  #    print 1 if board[x][y] else 0,
  #  print

  longest = [[0]*M for i in xrange(N)]

  for y in xrange(M):
    longest[N-1][y] = 1
    for x in xrange(N-2, -1, -1):
      if board[x][y] != board[x+1][y]:
        longest[x][y] = 1 + longest[x+1][y]
      else:
        longest[x][y] = 1

  tilesleft = N*M
  number = None
  while tilesleft > 0:
    biggest = 1
    where = (0, 0)
    for y in xrange(M):
      for x in xrange(N):
        if used[x][y]:
          continue
        width = longest[x][y]
        height = 1
        size = 1
        while height < width and y + height < M and board[x][y+height-1] != board[x][y+height]:
          width = min(width, longest[x][y+height])
          height += 1
          size = max(size, min(width, height))
        if size > biggest:
          biggest = size
          where = (x, y)
    if number is None:
      number = [0]*(biggest+1)
    if biggest != 1:
      #print "found", biggest, where
      number[biggest] += 1
      tilesleft -= biggest*biggest
      for i in xrange(biggest):
        x = where[0]
        y = where[1] + i
        while x > 0 and board[x-1][y] != board[x][y] and not used[x-1][y]:
          longest[x-1][y] -= longest[where[0]][y]
          x -= 1
      for i in xrange(biggest):
        for j in xrange(biggest):
          used[where[0]+i][where[1]+j] = True 
          longest[where[0]+i][where[1]+j] = 0
    else:
      number[1] += tilesleft
      tilesleft = 0
    #print case, tilesleft, "::"
    #for y in xrange(M):
    #  for x in xrange(N):
    #    print "%4d" % (longest[x][y],),
    #  print
  K = 0
  for i in xrange(len(number)-1, 0, -1):
    if number[i] > 0:
      K += 1
  print "Case #%d: %d" % (case, K)
  for i in xrange(len(number)-1, 0, -1):
    if number[i] > 0:
      print i, number[i]




