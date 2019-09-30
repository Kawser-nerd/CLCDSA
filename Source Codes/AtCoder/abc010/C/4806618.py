xa,ya,xb,yb,T,V = map(int,input().split())
R = T*V
n = int(input())

ans = "NO"

for i in range(n):
    x,y = map(int,input().split())
    if ((x-xa)**2 + (y-ya)**2)**0.5 + ((x-xb)**2 + (y-yb)**2)**0.5 <= R:
        ans = "YES"
        break

print(ans)