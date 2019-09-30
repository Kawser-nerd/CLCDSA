n,a,b = map(int,input().split())
l = list(map(int,input().split()))
s = 0
for i in range(n-1):
  s += min((l[i+1]-l[i])*a,b)
print(s)