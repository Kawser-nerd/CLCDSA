N=int(input())
NG1=int(input())
NG2=int(input())
NG3=int(input())

temp = [0]*N + [1]
NG_list = [ng for ng in [NG1,NG2,NG3] if ng<=N]

def ope(temp):
  for ng in NG_list:
    temp[ng]=0
    
  if sum(temp)==0:
    print('NO')
    exit()
  temp = [max(a,b,c) for a,b,c in zip(temp[1:]+[0], temp[2:]+[0,0], temp[3:]+[0,0,0])]
  if temp[0]==1:
    print('YES')
    exit()
  return temp
for _ in range(100):
  temp = ope(temp)

print('NO')