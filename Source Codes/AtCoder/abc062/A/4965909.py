a,b=map(int,input().split())
g1=[1,3,5,7,8,10,12]
g2=[4,6,9,11]
g3=[2]
if a in g1 and b in g1:
  print('Yes')
elif a in g2 and b in g2:
  print('Yes')
elif a in g3 and b in g3:
  print('Yes')
else:
  print('No')