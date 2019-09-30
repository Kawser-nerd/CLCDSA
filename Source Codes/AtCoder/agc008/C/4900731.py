a = list(map(int, input().split()))

ans = a[1] + 2*(a[0]//2 + a[4]//2 + a[3]//2)
if a[0]>0 and a[3]>0 and a[4]>0:
  ans = max(ans, a[1] + 2*((a[0]-1)//2 + (a[3]-1)//2 + (a[4]-1)//2) + 3)
  
print(ans)