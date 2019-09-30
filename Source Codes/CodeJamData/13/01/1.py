import sys

def hasWon(game, player):
    for ii in range(4):
        success = True
        for jj in range(4): # Has the player won in row ii
            if game[4*ii + jj] != player and game[4*ii + jj] != "T":
                success = False
        if success: return True
        success = True
        for jj in range(4): # Has the player won in column ii
            if game[4*jj + ii] != player and game[4*jj + ii] != "T":
                success = False
        if success: return True
    
    success = True
    for ii in range(4):
        if game[ii*5] != player and game[ii*5] != "T":
            success = False
    if success: return True
    success = True
    for ii in range(4):
        if game[3+ii*3] != player and game[3+ii*3] != "T":
            success = False
    if success: return True
    return False

def gameOver(game):
    ret_val = True
    for ii in range(16):
        if game[ii] == ".":
            ret_val = False
    return ret_val

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    game = []
    for ii in range(4):
        for elem in f.readline().strip():
            game.append(elem)

    if hasWon(game, "O"):
        print "Case #%d:" % (t + 1), "O won"
    elif hasWon(game, "X"):
        print "Case #%d:" % (t + 1), "X won"
    elif gameOver(game):
        print "Case #%d:" % (t + 1), "Draw"
    else:
        print "Case #%d:" % (t + 1), "Game has not completed"

    f.readline()
