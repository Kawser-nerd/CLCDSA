n = int(input())
k = int(input())
num = 1
for i in range(n):
    num = min(num + k, num * 2)
print(num)