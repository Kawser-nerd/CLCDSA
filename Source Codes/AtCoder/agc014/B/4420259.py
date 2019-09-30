N,M = [int(i) for i in input().split()]

q = [0] * N
for _ in range(M):
    a,b = [int(i) for i in input().split()]
    q[a-1] += 1
    q[b-1] += 1

for i in range(M):
    if q[i]%2 != 0:
        print('NO')
        exit()

print('YES')