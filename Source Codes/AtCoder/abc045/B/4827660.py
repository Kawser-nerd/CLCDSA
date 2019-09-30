sa = list(input())
sb = list(input())
sc = list(input())


turn = "a"

while(1):
  if turn == "a":
    if not sa: break
    turn = sa[0]
    del sa[0]
  if turn == "b":
    if not sb: break
    turn = sb[0]
    del sb[0]
  if turn == "c":
    if not sc: break
    turn = sc[0]
    del sc[0]
    
print(turn.upper())