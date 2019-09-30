n = int(input())

num = 0
for i in range(n):
    l, r = [int(n) for n in input().split()]
    num += (r - l + 1)

print(num)