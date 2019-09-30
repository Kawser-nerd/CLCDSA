n = int(input())

boss = [[] for i in range(n)]
for i in range(n - 1):
    a = int(input())
    boss[a - 1].append(i + 2)
    
salary = [0] * n
for i in range(n - 1, -1, -1):
    if len(boss[i]) == 0:
        salary[i] = 1
    elif len(boss[i]) == 1:
        salary[i] = salary[boss[i][0] - 1] * 2 + 1
    else:
        pool = []
        for b in boss[i]:
            pool.append(salary[b - 1])
        salary[i] += max(pool) + min(pool) + 1

print(salary[0])