a, b = map(int, input().split())
sa = str(a)
sb = str(b)

digit = [str(i) for i in range(0, 10)]

ans = -(2**32)

for i in range(3):
    for j in range(len(digit)):
        if i == 0 and j == 0:
            continue
        ta = int(sa[:i]+digit[j]+sa[i+1:])
        ans = max(ans, ta-b)

for i in range(3):
    for j in range(len(digit)):
        if i == 0 and j == 0:
            continue
        tb = int(sb[:i]+digit[j]+sb[i+1:])
        ans = max(ans, a-tb)

print(ans)