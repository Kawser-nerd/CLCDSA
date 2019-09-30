n = int(input())

min_cost = 10**9
for i in range(1,n+1):
    for j in range(1, n//i + 1):
        cost = abs(i-j) + n-(i*j)
        min_cost = min(min_cost, cost)

print(min_cost)