N = int(input())
costs = [[int(v) for v in input().split()] for i in range(N)]
 
costs_negative = sorted([v for v in costs if v[0] <  v[1]], key=lambda a: a[0])
costs_zero     = [v for v in costs if v[0] == v[1]]
costs_positive = sorted([v for v in costs if v[0] >  v[1]], key=lambda a: a[1], reverse=True)
 
val = 0
max_val = -float("inf")
for up, down in costs_negative + costs_zero + costs_positive:
    val += up
    if val > max_val:
        max_val = val
    val -= down
    
print(max_val)