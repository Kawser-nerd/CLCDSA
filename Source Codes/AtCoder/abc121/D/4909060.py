import math

A,B = map(int, input().split())
ans = int(0)
if B==0:
  ans = 0
else:
  N = math.floor(math.log2(B)+1)
  
  A_mod = A % 4
  B_mod = B % 4
  if A_mod < 2:
    if B_mod ==1 or B_mod == 2:
      ans += 1
  else:
    if B_mod ==3 or B_mod == 0:
      ans += 1

  for i in range(2,N+1):
    A_mod = A % (2**i)
    B_mod = B % (2**i)
    if A_mod < 2**(i-1):
      if B_mod >= 2**(i-1):
        ans += ((B_mod+1)%2)*(2**(i-1))
    else:
      if B_mod < 2**(i-1):
        ans += (A_mod%2)*(2**(i-1))
      else:
        ans += ((A_mod+B_mod+1)%2)*(2**(i-1))

print(ans)