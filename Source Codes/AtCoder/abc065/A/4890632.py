X, A, B = map(int, input().split())
over = -A + B
print('delicious' if over <= 0 else 'safe' if over <= X else 'dangerous')