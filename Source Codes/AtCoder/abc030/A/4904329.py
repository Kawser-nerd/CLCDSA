[a,b,c,d] = [int(i) for i in input().split()]

if a/b == c/d:
  print("DRAW")
elif a/b < c/d:
  print("TAKAHASHI")
else:
  print("AOKI")