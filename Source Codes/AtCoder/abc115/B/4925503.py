n = int(input())
l = [0] * n

for i in range(n):
    p = int(input())
    l[i] = p
max_p = max(l) // 2
ans = sum(l) - max_p
print(ans)