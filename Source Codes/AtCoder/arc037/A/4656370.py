N = int(input())
m = [int(_) for _ in input().split()]
sum = 0

for i in m:
    sum += max(0, 80-i)

print(sum)