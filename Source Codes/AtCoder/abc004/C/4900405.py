n = int(input())%30
cards = ['1','2','3','4','5','6']
for i in range(n):
    i = i%5
    cards[i],cards[i+1] = cards[i+1],cards[i]
print(''.join(cards))