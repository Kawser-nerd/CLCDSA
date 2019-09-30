a, b = ((int(x) - 2) % 100 for x in input().split())
print('Draw' if a == b else 'Alice' if a > b else 'Bob')