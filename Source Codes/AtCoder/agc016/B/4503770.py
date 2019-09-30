n = int(input())
a = list(map(int, input().split()))

unum = min(a)
vnum = max(a)

u = a.count(unum)
v = a.count(vnum)

exist = False

if vnum-unum == 1:
  if u+1 <= vnum <= u+v//2:
    exist = True
    
elif vnum == unum:
  if vnum == n-1 or vnum <= n//2:
    exist = True
    
print("Yes" if exist else "No")