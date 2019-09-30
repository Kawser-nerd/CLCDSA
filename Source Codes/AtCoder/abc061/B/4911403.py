N, M = map(int,input().split())

nodes = [0] * N

for i in range(0,M):
    a,b = map(int,input().split())
    nodes[a - 1] += 1
    nodes[b - 1] += 1

for i in range(0,N):
    print(nodes[i])