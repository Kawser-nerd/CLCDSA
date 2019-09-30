N, A, B = map(int, input().split())
total = 0
for i in range(N):
    s, d = input().split()
    d = int(d)
    if s == 'East':
        s = -1
    else:
        s = 1
    if d < A:
        move = A
    elif A <= d and d <= B:
        move = d
    elif B < d:
        move = B
    total += move*s
if total < 0:
    print('East', abs(total))
elif total > 0:
    print('West', abs(total))
else:
    print(total)