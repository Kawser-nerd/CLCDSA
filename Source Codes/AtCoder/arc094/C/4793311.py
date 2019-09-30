n = int(input())
a = [0] * n
b = [0] * n

temp = 10 ** 10
for i in range(n):
    a[i], b[i] = map(int, input().split())
    if a[i] > b[i]:
        temp = min(temp, b[i])

if temp == 10 ** 10:
    print(0)
else:
    print(sum(a) - temp)