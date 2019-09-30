H, W = map(int, input().split())
square = [["#"]*(W+2)] + [["#"]+list(input())+["#"] for _ in [0]*H] + [["#"]*(W+2)]
result = [[0]*(W+2) for _ in [0]*(H+2)]

for y in range(H, 0, -1):
    for x in range(W, 0, -1):
        if square[y][x] == "#":
            continue
        if result[y][x] == 0:
            result[y-1][x] = result[y][x-1] = result[y-1][x-1] = 1

print("First" if result[1][1] else "Second")