N = int(input())
lst = []

for i in range(N):
    x, y = map(int, input().split())

    lst.append([x, y])

res = 0
for i in range(N-1):
    for j in range(i+1, N):
        res = max(res, ((lst[j][0] - lst[i][0])**2 + (lst[j][1] - lst[i][1])**2)**(1/2))

print('{:.6f}'.format(res))