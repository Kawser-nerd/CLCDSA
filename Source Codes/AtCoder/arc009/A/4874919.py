N = int(input())
num = 0
for i in range(N):
    a, b = map(int, input().split())
    num += a * b

print(int(num * 1.05))