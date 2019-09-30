h, w = [int(item) for item in input().split()]
field = ["%" * (w+2)] + ["%" + input() + "%" for _ in range(h)] + ["%" * (w+2)]
for i in range(1,h+1):
    for j in range(1,w+1):
        count = 0
        if field[i][j] == ".":
            for k in [-1,0,1]:
                for l in [-1,0,1]:
                    if field[i+k][j+l] == "#":
                        count += 1
            field[i] = field[i][:j] + str(count) + field[i][j+1:]

for line in field[1:h+1]:
    for c in line:
        if c !="%":
            print(c, end="")
    print("")