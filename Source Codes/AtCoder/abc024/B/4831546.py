n, t = map(int, input().split())
total = 0
open_till = 0
for _ in range(n):
    a = int(input())
    if a < open_till:
        total += t - (open_till - a)
        open_till = a + t
    else:
        total += t
        open_till = a + t
print(total)