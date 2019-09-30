def main():
    coord = [list(map(int, input().split())) for _ in range(4)]
    for y in range(4):
        for x in range(1, 4):
            if coord[y][x] == coord[y][x - 1]:
                print("CONTINUE")
                return
    for y in range(1, 4):
        for x in range(4):
            if coord[y][x] == coord[y - 1][x]:
                print("CONTINUE")
                return
    print("GAMEOVER")


if __name__ == "__main__":
    main()