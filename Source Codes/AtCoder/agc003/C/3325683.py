n = int(input())

a = []

for i in range(n):
    a.append([int(input()), i])
    
a = sorted(a, key = lambda x:x[0])
ans = 0

for i in range(n):
    if i % 2 == 1 and (a[i][1] - i) % 2 == 1:
        ans += 1
        
print(ans)