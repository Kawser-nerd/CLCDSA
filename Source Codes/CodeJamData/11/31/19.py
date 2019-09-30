# Google Code Jam : Round 1C 2011 : Problem A. Square Tiles
# https://code.google.com/codejam/contest/dashboard?c=1128486#s=p0
# Python 2.6.5

def solve_case(t, tiles):
    R = len(tiles)
    C = len(tiles[0])

    impossible = False
    for r in range(R):
        for c in range(C):
            if tiles[r][c] == "#":
                try:
                    if tiles[r][c + 1] == "." or tiles[r + 1][c] == "." or tiles[r + 1][c + 1] == ".":
                        impossible = True 
                        break   

                    tiles[r][c] = "/"
                    tiles[r][c + 1] = "\\"
                    tiles[r + 1][c] = "\\"
                    tiles[r + 1][c + 1] = "/"
                except IndexError:
                   impossible = True 
                   break

    print "Case #" + str(t) + ":"
    if impossible:
        print "Impossible"
    else:
        for s in tiles:
            print "".join(s)

def solve():
    T = int(raw_input())
    for t in range(1, T + 1):
        s = raw_input().split()
        R = int(s[0])
        C = int(s[1])

        tiles = []
        for i in range(R):
            s = raw_input().strip()
            tiles.append(list(s))

        solve_case(t, tiles)

solve()
