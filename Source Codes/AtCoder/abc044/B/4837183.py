w=input()
def solve():
  for j in [chr(i) for i in range(91,91+26)]:
    if w.count(j)%2!=0:
      print("No")
      return
  print("Yes")
  return

solve()