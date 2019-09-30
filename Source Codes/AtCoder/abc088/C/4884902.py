C = []
max_c = 0
for i in range(3):
  c = list(map(int,input().split()))
  C.append(c)
  max_c = max(max(c),max_c)

judge = 0 #0:??,1:?
for i in range(max_c+1):
  a1 = i #a1??????????
  b1,b2,b3 = C[0][0]-a1,C[0][1]-a1,C[0][2]-a1
  if( ((C[1][0]-b1)==(C[1][1]-b2))and((C[1][0]-b1)==(C[1][2]-b3)) ):#a2
    if( ((C[2][0]-b1)==(C[2][1]-b2))and((C[2][0]-b1)==(C[2][2]-b3)) ):#a3
       judge = 1
       break

if(judge == 0): print('No')
else: print('Yes')