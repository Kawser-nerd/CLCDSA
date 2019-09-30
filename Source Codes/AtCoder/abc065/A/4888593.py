x, a, b = [int(i) for i in input().split()]
if (a - b) >= 0:
    print('delicious')
elif (b - a) <= x:
    print("safe")
else:
    print('dangerous')