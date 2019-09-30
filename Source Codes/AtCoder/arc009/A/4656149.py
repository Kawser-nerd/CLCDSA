N = int(input())
sum = 0
for i in range(N):
    a, b = map(int, input().split())
    sum += a*b

print(int(sum*1.05))