s = input()

ans = 0
for i, x in enumerate(s):
    if i % 2 == 0 and x == 'p':
        ans -= 1
    elif i % 2 == 1 and x == 'g':
        ans += 1

print(ans)