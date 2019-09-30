n,h = map(int,input().split())
a,b,c,d,e = map(int,input().split())
money = float("inf")
for x in range(n+1):
    y = max(0,((n-x)*e-h-b*x)//(d+e)+1)
    money = min(money,a*x+c*y)
print(money)