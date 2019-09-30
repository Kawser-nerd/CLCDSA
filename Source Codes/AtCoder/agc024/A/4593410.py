a,b,c,k=(int(i) for i in input().split())
def ans(x):
  if abs(x)>=10e18:
    return 'Unfair'
  else:
    return x
if k%2==0:
  print(ans(a-b))
else:
  print(ans(b-a))