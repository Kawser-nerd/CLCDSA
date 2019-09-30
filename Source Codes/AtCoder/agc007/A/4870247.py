H, W = [int(x) for x in input().split()]
A_s = [input() for _ in range(H)]

pos = [0, 0]
num = 1
while True:
    if pos == [H - 1, W - 1]:
        total = sum(map(lambda A: A.count("#"), A_s))
        ans = total == num
        break
    h, w = pos
    if h != H - 1 and A_s[h + 1][w] == "#":
        pos = [h + 1, w]
        num += 1
        continue
    if w != W - 1 and A_s[h][w + 1] == "#":
        pos = [h, w + 1]
        num += 1
        continue
    ans = False
    break

print("Possible" if ans else "Impossible")