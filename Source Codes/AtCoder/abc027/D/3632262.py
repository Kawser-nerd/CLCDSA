S = list(input())
count = []
p = 0
for s in S[::-1]:
    if s == '+':
        p += 1
    elif s == '-':
        p -= 1
    else:
        count.append(p)
count.sort()
half = len(count) // 2
print(sum(count[half:]) - sum(count[:half]) )