for case in xrange(1, int(raw_input())+1):
  N = int(raw_input())
  results = [raw_input() for _ in xrange(N)]
  wins  = [len(filter(lambda r: r == '1', results[i])) for i in xrange(N)]
  games = [len(filter(lambda r: r != '.', results[i])) for i in xrange(N)]
  wp = [float(wins[i]) / games[i] for i in xrange(N)]
  wp_ = [[float(wins[i] - (1 if results[i][j] == '1' else 0)) / (max(1, games[i] - (1 if results[i][j] != '.' else 0))) for j in xrange(N)] for i in xrange(N)]
  owp = [0] * N
  for i in xrange(N):
    for j in xrange(N):
      if results[i][j] != '.':
        owp[i] += wp_[j][i]
    owp[i] /= games[i]
  oowp = [0] * N
  for i in xrange(N):
    for j in xrange(N):
      if results[i][j] != '.':
        oowp[i] += owp[j]
    oowp[i] /= games[i]
  print "Case #%d: " % (case,)
  for i in xrange(N):
    print "%.10f" % (0.25*wp[i] + 0.50*owp[i] + 0.25*oowp[i])
