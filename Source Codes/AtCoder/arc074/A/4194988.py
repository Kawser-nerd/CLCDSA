H, W = (int(i) for i in input().split())
ans = float("inf")
for i in range(1,H):
  a, b = (i, W)
  S = W*(H-i)
  if a%2==0 or b%2==0:
    ans = min(ans, abs(S-a*b//2))
  else:
    if a == 1 and b ==1:
      continue
    else:
      Sbig = (max(a, b)+1)*min(a, b)//2
      Ssma = (max(a, b)-1)*min(a, b)//2
      Sdiff = max(abs(S-Sbig), abs(S-Ssma), abs(Sbig-Ssma))
      ans = min(ans, Sdiff)
      
H, W = (W, H)
for i in range(1,H):
  a, b = (i, W)
  S = W*(H-i)
  if a%2==0 or b%2==0:
    ans = min(ans, abs(S-a*b//2))
  else:
    if a == 1 and b ==1:
      continue
    else:
      Sbig = (max(a, b)+1)*min(a, b)//2
      Ssma = (max(a, b)-1)*min(a, b)//2
      Sdiff = max(abs(S-Sbig), abs(S-Ssma), abs(Sbig-Ssma))
      ans = min(ans, Sdiff)
print(ans)