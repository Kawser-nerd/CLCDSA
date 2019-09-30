D = [int(i) for i in input().split()]
J = [int(i) for i in input().split()]
ans = 0
for i in range(7):
    ans += max(D[i], J[i])
    
print(ans)