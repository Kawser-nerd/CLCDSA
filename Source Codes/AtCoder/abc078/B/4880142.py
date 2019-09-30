X, Y, Z = map(int, input().split())

ans = 0
width_sum = 0

while 1:
    if width_sum + Y + Z <= X-Z:
        width_sum += Y + Z
        ans += 1
    else:
        break

print(ans)