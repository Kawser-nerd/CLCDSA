N, M = map(int, input().split())
disk = [i for i in range(1,N+1)]
bf = 0
for i in range(M):
    a = int(input())
    if bf == a:
        continue
    else:
        b = disk.index(a)
        disk[b] = bf
        bf = a
for i in range(N):
    print(disk[i])