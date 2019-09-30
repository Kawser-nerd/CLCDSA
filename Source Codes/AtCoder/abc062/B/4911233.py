H,W = map(int,input().split())

print("#" * (W + 2))
for i in range(0,H):
    print("#" + input() + "#")

print("#" * (W + 2))