n = int(input())
a = [int(_) for _ in input().split()]

if n%2==0:
    s = a[n-1::-2] + a[::2]
else:
    s = a[n-1::-2] + a[1::2]

print(*s)