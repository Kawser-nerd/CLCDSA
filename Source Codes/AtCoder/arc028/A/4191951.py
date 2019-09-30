N, A, B = map(int, input().split())

turn = True
while N > 0:
    if turn:
        N -= A
    else:
        N -= B
    turn = not turn

print('Bug' if turn else 'Ant')