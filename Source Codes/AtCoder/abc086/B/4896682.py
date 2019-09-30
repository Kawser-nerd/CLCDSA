a = input().split()
s = int(a[0] + a[1])
n = int(s**0.5)
if n ** 2 == s or (n-1)**2 == s or (n+1)**2 == s:
    print("Yes")
else:
    print("No")