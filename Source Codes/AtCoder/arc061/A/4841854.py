import itertools

S = input()

total = 0
prev = 0
for p in itertools.product([False, True], repeat=len(S)-1):
    prev = 0
    for i in range(len(p)):
        if p[i]:
            total += int(S[prev:i+1])
            prev = i+1
    total += int(S[prev:])

if total == 0:
    total = int(S)
print(total)