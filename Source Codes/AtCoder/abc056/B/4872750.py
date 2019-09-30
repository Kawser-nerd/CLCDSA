w, a, b = map(int, input().split())
ans = 0

if a+w < b:
    ans = b-(a+w)
elif b+w < a:
    ans = a-(b+w)
else:
    ans = 0

print(ans)