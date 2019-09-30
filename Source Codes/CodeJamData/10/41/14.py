import sys
def read_values():
  return map(int,raw_input().split())

for case_index in range(1, 1+input()):

  k = int(input())
  c = [[0]*k for i in range(k)]
  i=0
  j=k-1
  for u in range(2*k-1):
    v = read_values()
    for m in range(len(v)):
      c[i+m][j+m]=v[m]
    if j>0:
      j-=1
    else:
      i+=1
  
  r = 0
  done = False
  while True:

    ci = k-1-r
    cj = k-1-r
    for step in range(max(1,4*r)):

      # center at (ci/2, cj/2) ?
      ok = True
      for i in range(k):
        for j in range(k):
          si = j+(-cj+ci)/2
          sj = i+ (cj-ci)/2
          if si>=0 and si<k and sj>=0 and sj<k:
            ok &= c[i][j]==c[si][sj]
          si = -j+(cj+ci)/2
          sj = -i+(cj+ci)/2
          if si>=0 and si<k and sj>=0 and sj<k:
            ok &= c[i][j]==c[si][sj]
          si = ci-i
          sj = cj-j
          if si>=0 and si<k and sj>=0 and sj<k:
            ok &= c[i][j]==c[si][sj]
          if not ok:
            break
        if not ok:
          break
      if ok:
        done = True
        break

      if step<r:
        ci+=2
      elif step<2*r:
        cj+=2
      elif step<3*r:
        ci-=2
      else:
        cj-=2

    if done:
      break
    r+=1
  
  res = 0
  side = 2*k+1
  while r>0:
    res += side
    side += 2
    r-=1

  sys.stderr.write(str(case_index)+' ')
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')
