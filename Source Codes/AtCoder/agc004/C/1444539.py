import sys
stdin = sys.stdin
readline = sys.stdin.readline

H, W = map(int, readline().split())
red, blue = [], []
r_append, b_append = red.append, blue.append
for _ in [None]*(H//2):
    r_append(list("#"*(W-1)+"."))
    r_append(list("#"+"."*(W-1)))
    b_append(list("."*(W-1)+"#"))
    b_append(list("."+"#"*(W-1)))
if H%2:
    r_append(list("#"*(W-1)+"."))
    b_append(list("."*(W-1)+"#"))

for y in range(H):
    for x, c in enumerate(readline()):
        if c == "#":
            if red[y][x] == ".":
                red[y][x] = "#"
            else:
                blue[y][x] = "#"

join = "".join
for line in red:
    print(join(line))
print()
for line in blue:
    print(join(line))