n = int(input())
a = list(map(int, input().split()))

a = sorted(a, reverse=True)
first_player = 0
second_player = 0
for i in range(n):
    if i % 2 == 0:
        first_player += a[i]
    else:
        second_player += a[i]

print(first_player)