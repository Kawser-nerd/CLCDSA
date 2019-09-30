n = int(input())
s = str(n)
s = sum( [ int(i) for i in s  ] )
if n % s == 0:
    print("Yes")
else:
    print("No")