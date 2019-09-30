def add_folder(s):
  folder = '/'
  aux = 0
  idx = 1
  for word in s.split('/')[1:]:
    folder += word + '/'
    if folder not in dirs:
      dirs.add(folder)
      aux += 1
  return aux

f = open('a.in', 'r')
T = int(f.readline())
for t_no in range(1, T + 1):
  dirs = set()
  N, M = [int(x) for x in f.readline().split()]
  for i in range(N):
    s = f.readline()[:-1]
    add_folder(s)
  sol = 0
  for i in range(M):
    s = f.readline()[:-1]
    sol += add_folder(s)
  print 'Case #%s: %s' % (t_no, sol)
