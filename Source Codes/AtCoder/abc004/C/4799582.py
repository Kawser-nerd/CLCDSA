N = int(input()) % 30

card = ['1', '2', '3', '4', '5', '6']


def sort(Card, n):
    tmp = n//5
    idx = n % 5
    for i in range(tmp):
        Card.append(Card.pop(0))
    Card.insert(idx, Card.pop(0))
    print(''.join(Card))


sort(card, N)