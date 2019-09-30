p=float(input())
f=lambda x:x+p*(2**(-x/1.5))

ub=1000
lb=0

for _ in range(200):
    a=(ub+2*lb)/3
    b=(2*ub+lb)/3
    if f(a)>f(b):
        lb=a
    else:
        ub=b
print(f((lb+ub)/2))