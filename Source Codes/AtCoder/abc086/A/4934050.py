a, b = [int(i) for i in input().split()]
ans = a * b
if ans % 2 == 0:
    print('Even')
else:
    print('Odd')