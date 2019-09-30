n = int(input())

a = [0,0,1]
if n > 3:
    for i in range(n - 3):
        i = i + 1
        a[(i % 3) - 1] = (a[0] + a[1]  + a[2]) % 10007

print(a[(n % 3) -1])