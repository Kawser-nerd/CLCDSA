N = int(input())
card = []
for i in range(N):
    card.append(int(input()))
card.append(0)
ans = 0
for i in range(N):
    pair = card[i] // 2
    ans += pair
    card[i] -= pair * 2
    if card[i] == 1 and card[i+1] > 0:
        card[i] -= 1
        card[i+1] -= 1
        ans += 1
print(ans)