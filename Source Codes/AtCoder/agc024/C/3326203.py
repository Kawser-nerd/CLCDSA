N = int( input())
A = [ int( input()) for _ in range(N)]
now = 0
ans = 0
if A[0] != 0:
    ans = -1
else:
   for i in range(1,N):
       # if A[i] > i:
       #     ans = -1
       #     break
       if now + 1 == A[i]:
           ans += 1
           now += 1
       elif now >= A[i]:
           ans += A[i]
           now = A[i]
       else:
           ans = -1
           break
print(ans)