a,b=input().split()
m=-999
for i in range(3):
  x=''.join('9'*(i==j)or a[j]for j in range(3))
  m=max(m,int(x)-int(b))
  y=''.join([b[j],'0'*(i>0)or'1'][i==j]for j in range(3))
  m=max(m,int(a)-int(y))
print(m)