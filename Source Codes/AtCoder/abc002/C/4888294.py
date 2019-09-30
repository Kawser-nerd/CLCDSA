xa,ya,xb,yb,xc,yc = map(int,input().split())
print(abs((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya))/2)