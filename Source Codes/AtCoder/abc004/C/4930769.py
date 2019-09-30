import re
n = int(input())
card = [i+1 for i in range(6)]
for i in range(n%30):
    buf = card[(i % 5) + 1]
    card[(i % 5) + 1] = card[(i % 5)]
    card[(i % 5)] = buf
print(re.sub(r'\D', '', str(card)))