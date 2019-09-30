y = int(input())
m = int(input())
d = int(input())
if m in (1, 2):
    m += 12
    y -= 1

print(735369 - (365 * y + y // 4 - y // 100 + y // 400 + (306 * (m + 1)) // 10 + d - 429))