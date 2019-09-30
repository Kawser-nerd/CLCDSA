def twin_and_watermellon(N: int, A: int, B: int, command: list) -> tuple:
    WEST = 'West'
    EAST = 'East'

    x = 0
    for s, d in command:
        dx = d
        if d < A:
            dx = A
        elif B < d:
            dx = B

        if s == WEST:
            x -= dx
        else:  # EAST
            x += dx

    direction = ''
    if x < 0:
        direction = WEST
    elif x > 0:
        direction = EAST

    return direction, abs(x)


if __name__ == "__main__":
    N = 0
    N, A, B = map(int, input().split())
    command = []
    for _ in range(N):
        s, d = input().split()
        command.append((s, int(d)))

    d, x = twin_and_watermellon(N, A, B, command)
    if x == 0:
        print(0)
    else:
        print(d, x)