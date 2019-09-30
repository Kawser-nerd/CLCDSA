n,m = map(int,input().split())
if n < 0 and m < 0:
    ans = m - n
elif n < 0 and m > 0:
    ans = m - n - 1
else:
    ans = m - n
print(ans)