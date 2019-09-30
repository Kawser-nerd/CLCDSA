N = int( input())
A = [ int( input()) for _ in range(N)]
now = 0
ans = 0
if A[0] != 0:
    ans = -1
else:
   for i in range(1,N):
       a = A[i]
       if a > i:
           ans = -1
           break
       elif now + 1 == a:
           ans += 1
           now += 1
       elif now >= a:
           ans += a
           now = a
       else:
           ans = -1
           break
print(ans)