card = '1 2 3 4 5 6'.split()
for i in range(int(input()) % 30):
  card[i % 5], card[(i % 5) + 1] = card[(i % 5) + 1], card[i % 5]
print(''.join(card))