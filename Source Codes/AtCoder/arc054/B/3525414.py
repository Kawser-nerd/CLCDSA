P = float(input())

def FT(t):
  return t + P * pow(2, -t/1.5)

l = 0
r = P

# 200 times loop is enough to convergence
for i in range(200):
  nl = (2*l+r)/3
  nr = (l+2*r)/3
  #print(i, nl, nr, FT(nl), FT(nr))
  if FT(nl) > FT(nr):
    l = nl
  else:
    r = nr
    
print(FT(l))