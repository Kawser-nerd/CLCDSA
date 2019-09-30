from scipy.optimize import minimize
p=float(input())
t=lambda x:x + p/(2**(x/1.5))
c= (
  {'type': 'ineq', 'fun':lambda x: x },
  {'type': 'ineq', 'fun':t}
  )
m=minimize(t,x0=0,tol =0.1**9,constraints=c,method="COBYLA")
print(min(p,m.fun))