#74
n = int(input())
k = int(input())
x = list(map(int, input().split()))
sum = 0

for i in range(n):
    sum += 2*min(x[i], abs(k-x[i]))
print(sum)