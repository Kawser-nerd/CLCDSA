w, h, n = map(int, input().split())

vec = []

l = []
b = []
r = []
t = []
for i in range(n):
    x, y, x1, y1 = map(int, input().split())
    c = [x, y, x1, y1]
    if( ((c[0] == 0 or c[0] == w) or (c[1] == 0 or c[1] == h)) and ((c[2] == 0 or c[2] == w) or (c[3] == 0 or c[3] == h)) ):
        if x == 0:
            l.append([x, y, i])
        elif y == 0:
            t.append([x, y, i])
        elif x == w:
            r.append([x, y, i])
        elif y == h:
            b.append([x, y, i])
        if x1 == 0:
            l.append([x1, y1, i])
        elif y1 == 0:
            t.append([x1, y1, i])
        elif x1 == w:
            r.append([x1, y1, i])
        elif y1 == h:
            b.append([x1, y1, i])

sorted_node = (
          sorted(l, key=lambda x: x[1])
        + sorted(b, key=lambda x: x[0])
        + sorted(r, key=lambda x: x[1], reverse=True)
        + sorted(t, key=lambda x: x[0], reverse=True)
        )


stack = []

for node in sorted_node:
    if not stack or stack[-1] != node[2]:
        stack.append(node[2])
    else:
        stack.pop()

print("NO" if stack else "YES")