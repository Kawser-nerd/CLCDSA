s = int(input())
syo = True
ans = 1
while syo:
    if s == 4 or s == 1 or s == 2:
        print(ans + 3)
        break
    if s%2 == 1:
        s = s*3+1
    else:
        s //= 2
    ans += 1