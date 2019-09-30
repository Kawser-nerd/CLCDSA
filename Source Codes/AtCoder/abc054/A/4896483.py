a, b = map(int, input().split())
a = (a - 2) % 13
b = (b - 2) % 13
print("Alice" if a > b else "Bob" if b > a else "Draw")