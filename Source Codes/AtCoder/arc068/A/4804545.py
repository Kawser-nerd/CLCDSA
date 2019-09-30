x = int(input())
ans = 2*(x//11)
if 1<=x%11<=6: 
  ans += 1
elif 7<=x%11: 
  ans += 2
print(ans)