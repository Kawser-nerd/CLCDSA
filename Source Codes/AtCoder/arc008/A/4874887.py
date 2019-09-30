n = int(input())
num = float('inf')
for i in range(100):
    num = min(num, i * 100 + max(0, (n - i * 10)) * 15)
print(num)