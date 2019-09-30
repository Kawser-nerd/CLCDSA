H, W, h, w = map(int, input().split())

if h*w == 1:
    print("No")
    exit()

plus = 1000
matrix = [[plus]*W for _ in [0]*H]
minus, total = -h*w*plus+plus-1, H*W*plus
y, x = h-1, w-1

for y in range(h-1, H, h):
    for x in range(w-1, W, w):
        matrix[y][x] = minus
        total += minus-plus

if total <= 0:
    print("No")
else:
    print("Yes")
    for row in matrix:
        print(*row)