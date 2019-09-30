s = input()

stones = [1 if v == 'W' else 0 for v in s]

cnt = 0
for a, b in zip(stones, stones[1:]):
    if a ^ b:
        cnt += 1
print(cnt)