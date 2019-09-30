N,H = map(int,input().split())
A,B,C,D,E = map(int,input().split())
min_cost = C*N

#H + BX +DY - (N-X-Y)E >0
#<=>  Y > {(N-X)E - H - BX} / (D+E)
for x in range(N+1):
   Y = max(  ((N-x)*E - H - B*x)//(D+E) + 1  , 0 )
   min_cost = min(min_cost , A*x + C*Y) 

print(min_cost)