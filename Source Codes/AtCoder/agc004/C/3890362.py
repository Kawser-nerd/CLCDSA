H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
ans = [["r" for _ in range(W)]] + [["." for _ in range(W)] for _ in range(H-2)] + [["b" for _ in range(W)]]

for h in range(1, H-1):
	for w in range(W):
		if a[h][w] == "#":
			ans[h][w] = "p"
		elif w % 2 == 0:
			ans[h][w] = "r"
		else:
			ans[h][w] = "b"

r = [["." for _ in range(W)] for _ in range(H)]
for h in range(H):
	for w in range(W):
		if ans[h][w] == "p" or ans[h][w] == "r":
			r[h][w] = "#"
for h in range(H):
	print("".join(r[h]))

print("\n")

b = [["." for _ in range(W)] for _ in range(H)]
for h in range(H):
	for w in range(W):
		if ans[h][w] == "p" or ans[h][w] == "b":
			b[h][w] = "#"
for h in range(H):
	print("".join(b[h]))