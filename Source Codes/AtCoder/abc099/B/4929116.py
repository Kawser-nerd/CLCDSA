a, b = map(int, input().split())
sum = 0
for i in range(1, b-a):
    sum += i
print(sum - a)