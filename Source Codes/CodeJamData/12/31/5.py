inp = open('./A-large.in', 'r')
outp = open('./A.out', 'w')

T = int(inp.readline())

def solve(i):
  N = int(inp.readline())
  classes = []
  for n in range(N):
    classes.append(set([ int(x) for x in inp.readline().replace('\n', '').split(' ') ][1:]))

  for n in range(N):
    for m in range(N):
        if n+1 in classes[m]:
          k = len(classes[n]) + len(classes[m])
          classes[m] = classes[n] | classes[m]
          if len(classes[m]) != k:
            outp.write('Case #' + str(i) + ': Yes\n')
            return
  
  outp.write('Case #' + str(i) + ': No\n')
    

for k in range(T):
  solve(k+1)

inp.close()
outp.close()
 