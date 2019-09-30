from collections import Counter

n = int(input())
inputs = [int(input()) for _ in range(n)]
counter = Counter(inputs)

answer = 0
for number, count in counter.items():
    if count % 2 != 0:
        answer += 1

print(answer)