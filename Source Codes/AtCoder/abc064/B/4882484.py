N = int(input())
a = list(map(int, input().split()))

a.sort()

result = 0
for i in range(N-1):
    result += a[i+1] - a[i]
print(result)