n = int(input())
a = int(input())

c = n // 500

one = n - c*500

if one <= a:
    print('Yes')
else:
    print('No')