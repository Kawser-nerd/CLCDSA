def ans():
  A, B = map(int,input().split())
  A, B = abs(A), abs(B)
  if(A < B):
    print("Ant")
  elif(A > B):
    print("Bug")
  else:
    print("Draw")
ans()