card = list(range(1,7))
N = int(input()) % 30

for i in range(N):
    tmp = card[i%5]
    card[i%5] = card[(i%5)+1]
    card[(i%5)+1] = tmp
for i in range(6):
    print(card[i],end="")