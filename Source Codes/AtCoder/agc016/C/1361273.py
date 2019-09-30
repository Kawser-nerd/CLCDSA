H, W, h, w = map(int, input().split())

if H % h == 0 and W % w == 0:
    print("No")
    exit(0)

blocks = (H//h) * (W//w)
left = H * W - blocks * h * w
offset = blocks // left + 1
v = [offset, -offset * (h * w - 1) - 1]

print("Yes")
for i in range(H):
    a = []
    for j in range(W):
        a.append(v[1 if i % h == h-1 and j % w == w-1 else 0])
    print(" ".join(list(map(str, a))))