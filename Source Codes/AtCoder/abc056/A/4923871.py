a,b = map(str, input().split())

if a == "H":
  if b == "H":
    print("H")
  else:
    print("D")
else:
  if b == "D":
    print("H")
  else:
    print("D")