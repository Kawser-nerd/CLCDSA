a,b,x = map(int, input().split())
ans = max((b//x) - ((a-1)//x), 0)
print(ans)