card = '1 2 3 4 5 6'.split()
for i in range(int(input()) % 30):
  a = (i % 5)
  b = (i % 5) + 1
  card[a], card[b] = card[b], card[a]
print(''.join(card))