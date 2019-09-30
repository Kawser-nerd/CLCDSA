N, H = map(int, input().split())
A, B, C, D, E = map(int, input().split())

X_max = (N*E-H)//(B+E) + 1

while True:
    if X_max<0:
        X_max += 1
    else:
        break
        
cost_min = X_max*A

for i in range(X_max+1):
    Y = (N*E-H-(B+E)*(X_max-i))//(D+E) + 1
    if Y>=0:
        cost = (X_max-i)*A + Y*C
        if cost < cost_min:
            cost_min = cost

print(cost_min)