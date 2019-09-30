import math

def prity(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            print(mat[i][j], end='')
        print()
        
def tile_a(i, j, mat):
    assert mat[i][j] == '.' and mat[i][j+1] == '.'
    mat[i][j] = '<'
    mat[i][j+1] = '>'
    
def tile_b(i, j, mat):
    assert mat[i][j] == '.' and mat[i+1][j] == '.'
    mat[i][j] = '^'
    mat[i+1][j] = 'v'
    
N, M, A, B = [int(_) for _ in input().split()]
a, b = A, B

mat = [['.' for j in range(M)] for i in range(N)]

if N % 2 == 1:
    i = N - 1 #tile last row
    for w in range(M // 2):
        if a > 0:
            j = 2 * w + (M % 2)            
            tile_a(i, j, mat)
            a -= 1

if M % 2 == 1:
    j = M - 1 # tile last column
    for h in range(N // 2):
        if b > 0:
            i = 2 * h
            tile_b(i, j, mat)
            b -= 1
            
height = N // 2
width = M // 2

skip_lst = []
if N % 2 == 1 and M % 2 == 1 and a % 2 == 1 and b % 2 == 1:
    tile_a(2 * (height - 1), 0, mat)
    tile_b(2 * (height - 1) + 1, 0, mat)
    a -= 1
    b -= 1
    skip_lst.append((2 * (height - 1), 0))
    
for h in range(height):
    for w in range(width):
        i = 2 * h
        j = 2 * w
        
        if not((i, j) in skip_lst):
            if a > 1:
                tile_a(i, j, mat)
                tile_a(i + 1, j, mat)
                a -= 2
            elif a == 1:
                tile_a(i, j, mat)
                a -= 1
            elif b > 1:
                tile_b(i, j, mat)
                tile_b(i, j + 1, mat)
                b -= 2
            elif b == 1:
                tile_b(i, j, mat)
                b -= 1
                
if a == 0 and b == 0:
    print("YES")
    prity(mat)
else:
    print("NO")