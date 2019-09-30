n = int(input())
sum = 0
for _ in range(n):
    x, u = input().split()
    if u =='JPY':
        sum+=(float(x))
    else:
        sum+=(float(x)*380000)
print("{:.5f}".format(sum))