n,a,b = map(int,input().split())
if n < 5:
    ans = n*b
else:
    ans = 5*b+(n-5)*a
print(ans)