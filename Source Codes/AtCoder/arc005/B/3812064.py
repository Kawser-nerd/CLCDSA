X, Y, W = input().split(" ")
X, Y = map(int, [X, Y])
C = [input() for _ in range(9)]

X, Y = X-1, Y-1
d = {
    "L": (-1, 0),
    "R": (1, 0),
    "U": (0, -1),
    "D": (0, 1)
}
d_x, d_y = [0, 0]
for w in W:
    x, y = d[w]
    d_x, d_y = d_x+x, d_y+y

t = C[Y][X]
for i in range(3):
    if not(0 <= X+d_x < 9):
        d_x *= -1
    if not(0 <= Y+d_y < 9):
        d_y *= -1
    X += d_x
    Y += d_y
    t += C[Y][X]

print(t)