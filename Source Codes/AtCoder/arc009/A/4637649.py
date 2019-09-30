n = int(input())
tot = 0
for i in range(n):
    a, b = map(int, input().split())
    tot += a*b

print(int(tot*1.05))