A=int(input())
C=int(input())
B=int(input())
mod=10**9+7

def power(x,y):
  if y==0:
    return 1
  elif y==1:
    return x%mod
  elif y%2==0:
    return power(x,y//2)**2%mod
  else:
    return (power(x,y//2)**2)*x%mod
  
inv=power(A*B+A*C-B*C,mod-2)
i=(((2*B*C-A*B-A*C)%mod)*inv)%mod
j=A*B*inv-1
print((i-j)%mod,j%mod)