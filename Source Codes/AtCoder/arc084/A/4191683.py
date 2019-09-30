import bisect 
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))

a = sorted(a)
b = sorted(b)
c = sorted(c)
ans = 0
for i in range(n):
  ans += bisect.bisect_left(a,b[i])*(n-bisect.bisect_right(c,b[i]))
print(ans)