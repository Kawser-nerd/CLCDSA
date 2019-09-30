K,N=map(int,input().split())
gt = [''] * K
vs,ws = ['']*N,['']*N 
for i in range(N):
  vs[i],ws[i] = input().split()
vl,wl = list(map(len,vs)), list(map(len,ws))

def f(idx, vi, wi):
  if vl[idx] == vi and wl[idx] == wi:
    idx += 1
    vi,wi = 0,0
    if idx == N:
      print('\n'.join(gt))
      quit()
  elif vl[idx] > vi and wl[idx] > wi:
    pass
  else:
    return
  
  ivc = int(vs[idx][vi])-1
  g = gt[ivc]
  if g == '':
    for l in [1,2,3]:
      g = ws[idx][wi:wi+l]
      gt[ivc] = g
      f(idx, vi+1, wi+l)
      gt[ivc] = ''
  else:
    if ws[idx][wi:wi+len(g)] == g:
      f(idx, vi+1, wi+len(g))
    else:
      return

f(0, 0, 0)