n=int(input())
l=set()
b=""

for i in range(n):
  s=input()
  if s in l or (i and b!=s[0]):
    print("WIN" if i%2 else "LOSE")
    break
  b=s[-1]
  l.add(s)
else:
  print("DRAW")