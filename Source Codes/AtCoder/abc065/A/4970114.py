x, a, b = [int(item) for item in input().split()]

if b <= a:
    print("delicious") 
elif x >= b - a:
    print("safe")
else:
    print("dangerous")