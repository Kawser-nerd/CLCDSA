inp = open('./B-large.in', 'r')
outp = open('./B.out', 'w')

T = int(inp.readline())

def solve(i):
  I = inp.readline().replace('\n', '').split(' ')
  D = float(I[0])
  N = int(I[1])
  A = int(I[2])

  Ns = []

  for n in range(N):
    Ns.append([ float(x) for x in inp.readline().replace('\n', '').split(' ') ])
    if Ns[n][1] > D:
      if n != 0: Ns[n][0] = Ns[n-1][0] + (D - Ns[n-1][1]) / (Ns[n][1] - Ns[n-1][1]) * (Ns[n][0] - Ns[n-1][0]) 
      Ns[n][1] = D

  As = [ float(x) for x in inp.readline().replace('\n', '').split(' ') ]

  Mx = [0] * A

  for n in range(N):
    for a in range(A):
      Mx[a] = max(Mx[a], Ns[n][0] - (2*Ns[n][1]/As[a])**0.5)

  outp.write('Case #' + str(i) + ':\n')
  for a in range(A):
    x = (2*D/As[a])**0.5 + Mx[a]
    outp.write(str(x) + '\n')
    

for k in range(T):
  solve(k+1)

inp.close()
outp.close()