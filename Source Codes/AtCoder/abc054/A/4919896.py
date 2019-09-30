A, B = map(int, input().split())
cards = [num for num in range(2, 14)]
cards.append(1)

for i in reversed(cards):
    if i == A and i == B:
        print("Draw")
    elif i == A and i != B:
        print("Alice")
        break
    elif i == B and i != A:
        print("Bob")
        break