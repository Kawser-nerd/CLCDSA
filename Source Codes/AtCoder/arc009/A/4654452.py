N = int(input())
g = 0
for _ in range(N):
    a,b = map(int,input().split())
    g += a*b
print(int(g*1.05))