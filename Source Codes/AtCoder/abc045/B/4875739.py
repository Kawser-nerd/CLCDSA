players = {}
players["A"] = input()
players["B"] = input()
players["C"] = input()

now_play = "A"

while True:
    if len(players[now_play]) == 0:
        print(now_play)
        break

    trushed_card = players[now_play][0].upper()
    players[now_play] = players[now_play][1:]
    now_play = trushed_card