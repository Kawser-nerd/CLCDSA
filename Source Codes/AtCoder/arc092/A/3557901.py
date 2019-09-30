N = int(input())
r = [[0, 0] for i in range(N)]
b = [[0, 0] for i in range(N)]
for i in range(N):
    r[i][0], r[i][1] = map(int, input().split())
for i in range(N):
    b[i][0], b[i][1] = map(int, input().split())

r.sort(key=lambda x: (x[1]), reverse=True)
b.sort(key=lambda x: (x[0]))
r_flag = [False] * N
b_flag = [False] * N
count = 0

for i in range(N):
    for j in range(N):
        if r[j][0] < b[i][0] and r[j][1] < b[i][1] and not r_flag[j]:
            r_flag[j] = True
            count += 1
            break

print(count)