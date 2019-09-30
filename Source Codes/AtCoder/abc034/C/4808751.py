W, H = list(map(int, input().split()))
if W>H:
  W,H=H,W
  
mod=int(1e9+7)
# calc (W+H-2)C(W-1)   1...W-1  H...H+W-2
def prodmod(a,b):
  return a*b%mod
def divmod(a):
  return powermod(a,mod-2)
def powermod(a,n):
  if n==0:
    return 1
  if n==1:
    return a%mod
  
  if n%2:
    return powermod(a,n//2)**2*a%mod
  else:
    return powermod(a,n//2)**2%mod
  
from functools import reduce
print(prodmod(reduce(prodmod, list(range(H,H+W-1))),
              divmod(reduce(prodmod, list(range(1,W)))))
     )