w, a, b = map(int, input().split())
if a < b:
    if ((a <= b) & (b <= a+w)):
        ans = 0
    else:
        ans = abs(b-a-w)
elif a >= b:
    if ((b <= a) & (a <= b+w)):
        ans = 0
    else:
        ans = abs(a-b-w)
print(ans)