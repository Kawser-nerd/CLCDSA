import math
from decimal import *

n=int(input())

t_prev,a_prev=1,1
for i in range(n):
  t,a=map(int,input().split())
  n_koho1=math.ceil(Decimal(t_prev)/Decimal(t))
  n_koho2=math.ceil(Decimal(a_prev)/Decimal(a))

  #?????
  #n_koho1=math.ceil(t_prev/t)
  #n_koho2=math.ceil(a_prev/a)

  #???OK
  #n_koho1 = t_prev // t
  #n_koho2 = a_prev // a
  #if t_prev % t != 0:
  #    n_koho1 += 1
  #if a_prev % a != 0:
  #    n_koho2 += 1
        
  n=max(n_koho1,n_koho2)
  t=n*t
  a=n*a
    
  t_prev=t
  a_prev=a

print(t_prev+a_prev)