x, y = map(int, input().split())
A = {1, 3, 5, 7, 8, 10, 12}
B = {4, 6, 9, 11}
C = {2}
for X in A, B, C:
    if x in X and y in X:
        print('Yes')
        break
else:
    print('No')