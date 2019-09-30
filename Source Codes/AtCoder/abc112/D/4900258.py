N, M = map(int, input().split())
x = 0
m = 0
for i in range(10**5):
    if i**2 < M <= (i+1)**2:
        m = i+1
        break
if m >N:
    for i in range(N, m):
        if M % i == 0:
            x = M // i
            break
if x == 0:
    for i in reversed(range(1, M //N +1)):
        if M % i == 0:
            x = i
            break
print(x)