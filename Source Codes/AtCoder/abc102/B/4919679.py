# 2019/04/11
# AtCoder Beginner Contest 102 - B

n = int(input())
a = list(map(int, input().split()))

minval = 10 ** 10
maxval = 0
for i in range(n):
    if a[i] > maxval:
        maxval = a[i]
    if a[i] < minval:
        minval = a[i]

print(abs(maxval - minval))