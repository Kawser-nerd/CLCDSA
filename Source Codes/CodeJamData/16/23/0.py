from hopcroftkarp import HopcroftKarp

T = int(raw_input())

for t in range(T):
  N = int(raw_input())
  graph = {}
  aset = set()
  bs = set()
  for i in range(N):
    a, b = raw_input().split()
    b += '_'
    aset.add(a)
    bs.add(b)
    if a not in graph:
        graph[a] = set()
    graph[a].add(b)

  match = HopcroftKarp(graph).maximum_matching()
  r = len(match)/2
  print 'Case #%d: %d' % (t+1, N+r-len(aset)-len(bs))
