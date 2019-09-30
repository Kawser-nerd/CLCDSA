N = int(input())

cards = [1,2,3,4,5,6]

if N>=30:
    N = N%30
    
for i in range(N//5):
    for j in range (5):
        tmp = cards[j]
        cards[j] = cards[j+1]
        cards[j+1] = tmp

for i in range(N%5):
    tmp = cards[i]
    cards[i] = cards[i+1] 
    cards[i+1] = tmp
    
cards_str = map(str,cards)
print(''.join(cards_str))