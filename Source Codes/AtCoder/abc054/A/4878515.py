A, B = map(int, input().split())
a = (A - 2) % 13
b = (B - 2) % 13
print('Alice' if a > b else 'Bob' if a < b else 'Draw')