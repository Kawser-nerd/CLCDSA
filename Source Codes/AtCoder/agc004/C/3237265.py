h,w=map(int,input().split());r=[list('#'+'#.'[i%2]*(w-2)+'.')for i in range(h)];b=[list('.'+'.#'[i%2]*(w-2)+'#')for i in range(h)]
for i in range(h):
  t=input()
  for j in range(w):
    if t[j]=='#':r[i][j]=b[i][j]='#'
for t in r:print(''.join(t))
print()
for t in b:print(''.join(t))