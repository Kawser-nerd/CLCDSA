n = int(input())
w = input()
s = [w]
k = 1
for _ in [0]*(n-1):
  x = input()
  k += 1
  if x in s or x[0] != w[-1]:
    if k%2 == 0:
      print("WIN")
    else:
      print("LOSE")
    exit()
  else:
    s.append(x)
    w = x
print("DRAW")