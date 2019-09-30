n = int(input())
k = int(input())

x = [int(num) for num in input().split()]

l = 0
for i in range(n):
    if x[i] <= k - x[i]:
        l += 2 * x[i]
    else:
        l += 2 * (k - x[i])

print(l)