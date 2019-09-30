H, W = map(int, input().split())
ORG = [input() for _ in range(H)]
EDGE = "#" * (W + 2)
print(EDGE)
for org in ORG:
	print("#" + org + "#")
print(EDGE)