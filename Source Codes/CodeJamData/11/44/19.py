import psyco
psyco.full()
def main():
  T = input()
  for t in xrange(T):
    P,W = map(int,raw_input().split())
    line = raw_input().split(' ')
    g = [[] for p in xrange(P)]
    for l in line:
      a,b = map(int,l.split(','))
      g[a].append(b)
      g[b].append(a)
    gsets = [set(g[i]) for i in xrange(P)]
    Ls = [len(g[i]) for i in xrange(P)]
    old = []
    oldset = set()
    visited = set()
    if 1 in g[0]:
      print "Case #%d: 0 %d"%(t+1,Ls[0])
      continue
    for i in g[0]:
      oldset.add(i)
      old.append((i,set([i]),gsets[i]|gsets[0]))
    found = -1
    best = -1
    bestp = -1
    d = {}
    while 1:
      d.clear()
      for i in old:
        if 1 in gsets[i[0]]:
          found = 1
          tmp = len(i[2])-len(i[1])-1
          if tmp > best:
            best = tmp
            bestp = len(i[1])
          continue
        for j in g[i[0]]:
          if j in oldset or j in visited:
            continue
            
          aset = i[2]|gsets[j]
          if j in d:
            tmp = len(aset)-len(i[1])
            if tmp > d[j][0]:
              newset = i[1].copy()
              newset.add(j)
              d[j] = (tmp,j,newset,aset)
          else:
            tmp = len(aset)-len(i[1])
            newset = i[1].copy()
            newset.add(j)
            d[j] = (tmp,j,newset,aset)
      if found!=-1:
        break
      visited.update(oldset)
      oldset = set(d.keys())
      old = [k[1:] for k in d.values()]

    print "Case #%d:"%(t+1),bestp,best
main()
