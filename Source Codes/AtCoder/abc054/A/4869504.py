A, B = map(int, input().split())
if A == 1:
    A += 13
if B == 1:
    B += 13
print('Alice' if A > B else 'Draw' if A == B else 'Bob')