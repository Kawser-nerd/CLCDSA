a,b,c,d = map(int,input().split())

def f(x,y,z,w):
  return ((d-b)*(x-a)-(c-a)*(y-b))*((d-b)*(z-a)-(c-a)*(w-b)) < 0
def g(x,y,z,w):
  return ((w-y)*(a-x)-(z-x)*(b-y))*((w-y)*(c-x)-(z-x)*(d-y)) < 0

n = int(input())
x = [0]*n
y = [0]*n
for i in range(n):
  x[i],y[i] = map(int,input().split())
s = 0
for i in range(n):
  if f(x[i-1],y[i-1],x[i],y[i]) and g(x[i-1],y[i-1],x[i],y[i]):
    s += 1
print(s//2+1)