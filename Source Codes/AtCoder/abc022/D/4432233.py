from math import hypot

N = int(input())
a_items = []
for i in range(N):
    a_items.append(tuple(map(int, input().split())))
b_items = []
for i in range(N):
    b_items.append(tuple(map(int, input().split())))

ax, ay = 0, 0
for x, y in a_items:
    ax += x
    ay += y

bx, by = 0, 0
for x, y in b_items:
    bx += x
    by += y

ax /= N
ay /= N
bx /= N
by /= N

ca, cb = 0, 0
for i in range(N):
    a1, a2 = a_items[i]
    b1, b2 = b_items[i]
    ca += hypot(ax - a1, ay - a2)
    cb += hypot(bx - b1, by - b2)
print(cb / ca)