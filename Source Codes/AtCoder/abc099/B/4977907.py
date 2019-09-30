a, b = map(int, input().split())

sum = 0
for i in range(b-a):
    sum += i+1

print(sum-b)