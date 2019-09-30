def str2turn(c: str) -> int:
    if c.lower() == 'a':
        return 0
    elif c.lower() == 'b':
        return 1
    return 2


def turn2str(t: int) -> str:
    if t == 0:
        return 'a'
    elif t == 1:
        return 'b'
    return 'c'


def card_game_for_three(Sa: str, Sb: str, Sc: str) -> str:
    indexes = [0, 0, 0]
    limits = [len(Sa), len(Sb), len(Sc)]
    cards = [Sa, Sb, Sc]

    turn = 0
    while indexes[turn] < limits[turn]:
        next_turn = str2turn(cards[turn][indexes[turn]])
        indexes[turn] += 1
        turn = next_turn

    return turn2str(turn).upper()


if __name__ == "__main__":
    Sa = input()
    Sb = input()
    Sc = input()
    ans = card_game_for_three(Sa, Sb, Sc)
    print(ans)