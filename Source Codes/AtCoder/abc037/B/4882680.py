N, Q = map(int, input().split())
row = [0 for _ in range(N)]
lines = [[int(i) for i in input().split()] for _ in range(Q)]

for line in lines:
    for ind in range(line[0] - 1, line[1]):
        row[ind] = line[2]

for i in row:
    print(i)