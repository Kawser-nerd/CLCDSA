xa,ya,xb,yb,xc,yc = map(int,input().split())
ans = abs((xb-xa)*(yc-ya)-(yb-ya)*(xc-xa))/2
print(ans)