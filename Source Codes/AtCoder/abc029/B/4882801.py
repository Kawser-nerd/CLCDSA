S = [input() for i in range(12)]
count = 0
for i in range(12):
    if 'r' in S[i]:
        count += 1
print(count)