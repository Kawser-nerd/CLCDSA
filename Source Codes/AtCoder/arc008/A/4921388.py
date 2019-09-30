N = int(input())
d,m = divmod(N,10)
ans = d*100 + min(100, m*15)
print(ans)