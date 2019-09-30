W, a, b = map(int, input().split())
ans = 0
if a+W < b:
    ans = b-a-W
elif b+W < a:
    ans = a-b-W
else:
    ans = 0
print(ans)