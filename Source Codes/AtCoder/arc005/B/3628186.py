def main():
    x, y, w = input().split()
    x = int(x) - 1
    y = int(y) - 1

    c = []
    for _ in range(9):
        c.append(input())

    dx = 0
    dy = 0
    if 'R' in w:
        dx = 1
    if 'L' in w:
        dx = -1
    if 'U' in w:
        dy = -1
    if 'D' in w:
        dy = 1

    s = ''.join(get(c, x + dx * i, y + dy * i) for i in range(4))
    print(s)

def get(c, x, y):
    if x < 0:
        x = -x
    if x >= 9:
        x = 16 - x
    if y < 0:
        y = -y
    if y >= 9:
        y = 16 - y

    return c[y][x]

main()