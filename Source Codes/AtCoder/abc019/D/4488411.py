N = int(input())
M, a = 0, 0
for i in range(1, N):
    print("?", 1, i + 1)
    dist = int(input())
    if M < dist:
        M = dist
        a = i + 1
M = 0
for i in range(N):
    if i + 1 == a:
        continue
    print("?", a, i + 1)
    dist = int(input())
    if M < dist:
        M = dist
print("!", M)