def ans():
  y = int(input())
  m = int(input())
  d = int(input())
  if(m == 1 or m == 2):
    m += 12
    y -= 1
  a = 735369
  b = 365*y + y//4 - y//100 + y//400 + 306*(m+1)//10 + d - 429
  print(a-b)
ans()