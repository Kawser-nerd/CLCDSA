import sys
n=int(input())
w=[input() for i in range(n)]
if all(w[j][len(w[j])-1]==w[j+1][0] for j in range(n-1)) and len(set(w))==n:
  print('Yes')
  sys.exit()
print('No')