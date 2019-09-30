n = int(input())
w = 10007

a = [0]*n

for i in range(n):
    if i == 2:
        a[i] = 1
    elif i > 2:
        a[i] = a[i-1] + a[i-2] + a[i-3]
        a[i] %= w

print(a[n-1])