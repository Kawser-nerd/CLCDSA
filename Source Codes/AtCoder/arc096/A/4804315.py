a, b, c, x, y = map(int, input().split())
print(min(a*x + b*y, 2*c*max(x,y), 2*c*y + a*(x-y) +(10**10 if y > x else 0), 2*c*x + b*abs(y-x)+(10**10 if x > y else 0)))