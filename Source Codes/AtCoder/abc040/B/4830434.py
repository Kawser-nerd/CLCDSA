n=int(input())
ans=[]
for i in range(n):
  tate=1+i
  yoko=n//tate
  amari=n%tate
  ans.append(abs(tate-yoko)+amari)

print(min(ans))