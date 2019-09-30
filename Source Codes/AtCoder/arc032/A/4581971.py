n = int(input())
if n == 1:
  print("BOWWOW")
  exit()
s = n*(n+1)//2
for i in range(2,int(s**0.5)+1):
  if s%i == 0:
    print("BOWWOW")
    break
else:
  print("WANWAN")