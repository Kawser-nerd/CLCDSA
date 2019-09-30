x = set(list(map(int, input().split())))
a = set([1, 3, 5, 7, 8, 10, 12])
b = set([4, 6, 9, 11])
if len(x & a) == 2 or len(x & b) == 2:
    print('Yes')
else:
    print('No')