import queue

h, w = [int(i) for i in input().split(" ")]
s = ["" for i in range(0, h)]

for i in range(0, h):
    s[i] = input()

b = [[False for j in range(0, w)] for i in range(0, h)]

c = 0
for i in range(0, h):
    for j in range(0, w):
        if s[i][j] == ".":
            c += 1

q = queue.Queue()
q.put([0, 0, 0])
b[0][0] = True

def addq(i, j, d):
    global b
    global q
    if 0 <= i and i < h and 0 <= j and j < w and not b[i][j] and s[i][j] == ".":
        b[i][j] = True
        q.put([i, j, d])

f = False
while not q.empty():
    qi = q.get()
    if qi[0] == h - 1 and qi[1] == w - 1:
        f = True
        print(c - qi[2] - 1)
        break
    i = qi[0]
    j = qi[1]
    addq(i + 1, j, qi[2] + 1)
    addq(i, j + 1, qi[2] + 1)
    addq(i - 1, j, qi[2] + 1)
    addq(i, j - 1, qi[2] + 1)

if not f:
    print(-1)