

def solve(X,R,C):
  # True jak sie da zablokowac
  if (R*C)%X > 0:
    return True
  big = max(R,C)
  small = min(R,C)
  if X>=7:
    return True
  if X > big:
    return True
  if X > 2*small:
    return True
  if big==small:
    # X<=small
    return False
  if big==small+1:
    # na 80% ;)
    return False
  if big>=small+2:
    if X<2*small-1:
      return False
    if X==2*small-1:
      # X =1,3,5
      # s =1,2,3
      # b>=3,4,5
      if X==1:
        return False
      if X==3:
        return False
      if X==5:
        return big<=5
    if X==2*small:
      # X =2,4,6
      # s =1,2,3
      # b>=3,4,5
      if X==2:
        return False
      if X==4:
        return True
      if X==6:
        return True
      
      
  raise AssertionError()
    

T = input()

for t in range(1,T+1):
  (X,R,C) = map(int,raw_input().split(' '))
  s = solve(X,R,C)
  winner = "RICHARD" if s else "GABRIEL"
  print "Case #%d: %s" % (t,winner)
