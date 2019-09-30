S = input()
right_gain = []
g = 0
for c in S[::-1]:
    if c == '+':
        g += 1
    elif c == '-':
        g -= 1
    else:
        right_gain.append(g)

half = len(right_gain)//2
ans = 0
for i,g in enumerate(sorted(right_gain)):
    if i < half:
        g *= -1
    ans += g
print(ans)