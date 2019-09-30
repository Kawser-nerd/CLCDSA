import sys

p = ["A", "B", "C"]
p_dic = {"a": 0, "b": 1, "c": 2}

def card(cards, player):
  if len(cards[player]) == 0:
    print(p[player])
    sys.exit()
  else:
    x = cards[player][0]
    cards[player] = cards[player][1:]
    card(cards, p_dic[x])

cards = [input() for i in range(3)]
card(cards, 0)