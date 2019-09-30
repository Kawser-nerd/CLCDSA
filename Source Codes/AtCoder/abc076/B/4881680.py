N = int(input())
K = int(input())
num = 1
for i in range(N):
    num = min(num + K, num * 2)

print(num)