# encoding: utf-8
N = int(input())

def game(score, turn, depth):
    if score > N: return turn
    if depth % 2:
        if turn:
            return game(score * 2, 0, depth)
        else:
            return game(score * 2 + 1, 1, depth)
    else:
        if turn:
            return game(score * 2 + 1, 0, depth)
        else:
            return game(score * 2, 1, depth)

for depth in range(64):
    if (N >> depth) < 1: break

if game(1, 0, depth): print("Aoki")
else: print("Takahashi")