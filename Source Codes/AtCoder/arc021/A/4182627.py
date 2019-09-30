# -*- coding: utf-8 -*-
#! python3

grid = []
ans = 'GAMEOVER'

for _ in range(4):
    grid.append(input().split())

for i in grid:
    for j in range(3):
        if i[j] == i[j+1]:
            ans = 'CONTINUE'
            break
        
for k in range(3):
    for l in range(4):
        if grid[k][l] == grid[k+1][l]:
            ans = 'CONTINUE'
            break
        
print(ans)