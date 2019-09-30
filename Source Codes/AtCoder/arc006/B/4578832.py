n,l=map(int,input().split())
y=[i for i in range(n)]
def swap(n,m):
  y.insert(m+1,y[n])
  del y[n]
for i in range(l):
  a=list(input())
  for j in range(n-1):
    if a[((j+1)*2)-1]=="-":
      y.insert(j+2,y[j])
      del y[j]
x=list(input())
print(y[(round(x.index("o")/2))]+1)