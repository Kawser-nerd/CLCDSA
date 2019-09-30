g1 = [1, 3, 5, 7, 8, 10, 12]
g2 = [4, 6, 9, 11]
x, y = map(int, input().split())
print('Yes' if x in g1 and y in g1 or x in g2 and y in g2 else 'No')