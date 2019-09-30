cards = [1, 2, 3, 4, 5, 6]
n = int(input()) % 30

for i in range(n):
    tmp = cards[i%5]
    cards[i%5] = cards[i%5+1]
    cards[(i%5)+1] = tmp

print(*cards, sep='')