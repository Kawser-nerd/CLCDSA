a, b = map(int, input().split())

ans = {
    1: 'Positive',
    -1: 'Negative',
    0: 'Zero'
}

res = None
if a > 0:
    res = 1
elif a * b < 0 or a == 0 or b == 0:
    res = 0
else:
    res = (-1) ** ((abs(a - b) + 1) % 2)

print(ans[res])