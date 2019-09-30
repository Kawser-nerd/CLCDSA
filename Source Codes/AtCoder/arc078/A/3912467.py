n = int(input())
cards = list(map(int, input().split()))

a = 0
b = sum(cards)
min_diff = float('inf')
for i in range(n - 1):
    a += cards[i]
    b -= cards[i]
    min_diff = min(min_diff, abs(a - b))
print(min_diff)