a = [0, 0, 1]
n = int(input())
if n<4: exec("print(a[n-1]);exit()")
for i in range(n-3): a[0], a[1], a[2] = a[1], a[2], (a[0]+a[1]+a[2])%10007
print(a[2]%(10007))