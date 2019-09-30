y = int(input())
m = int(input())
d = int(input())
if m < 3:
  y -= 1
  m += 12
def date(y,m,d):
  return 365*y + y//4 - y//100 + y//400 + (306*(m+1))//10 + d - 429
print(date(2014,5,17) - date(y,m,d))