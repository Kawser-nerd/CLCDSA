card = list(range(1, 7))

N = int(input()) % 30
for i in range(N):
    m1 = i % 5
    m2 = m1 + 1
    card[m1], card[m2] = card[m2], card[m1]

map_result = map(str, card)
result = "".join(map_result)
print(result)