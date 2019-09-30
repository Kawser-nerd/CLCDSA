n = int(input())
a = [int(i) for i in input().split()]

res = -10**10
for i in range(n):
    max_score = -10**10
    t_score = 0
    for j in range(n):
        if i==j:
            continue
        
        t = a[min(i,j):max(i,j)+1]
        if max_score < sum(t[1::2]):
            max_score = sum(t[1::2])
            t_score = sum(t[::2])

    if t_score > res:
        res = t_score

print(res)