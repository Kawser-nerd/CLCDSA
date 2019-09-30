# coding: utf-8
# Your code here!
A,B = map(int,input().split())
h,w = 100, 100
grid = [['.' if j < 50 else '#' for i in range(w)] for j in range(h)]
A -= 1
B -= 1
reg = ['.' if i % 2 == 0 else '#' for i in range(w)]
for i in range(25):
    if B >= 50:
        grid[i*2] = reg
        B -= 50
    else:
        for j in range(B):
            grid[i*2][j*2] = '#'
        break
for i in range(25):
    if A >= 50:
        grid[99 - i*2] = reg
        A -= 50
    else:
        for j in range(A):
            grid[99 - i*2][j*2] = '.'
        break
print(h,w)
for row in grid:
    print(''.join(row))