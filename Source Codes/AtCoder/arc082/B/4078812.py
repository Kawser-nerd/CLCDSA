n = int(input())
p = [int(s) - 1 for s in input().split()]

ans = 0
for i in range(n):
    if p[i] != i: continue
    
    j = i - 1 if i + 1 == n else i + 1
    p[i], p[j] = p[j], p[i]
    ans += 1

print(ans)