def Yes():
  print("Yes")
def No():
  print("No")

def gcd(x, y):
  b = max(x, y)
  s = min(x, y)
  r = b % s
  while r != 0:
    b = s
    s = r
    r = b % s
  return s

def lcm(x, y):
  return (x * y) // gcd(x,y)

def main():
  T = int(input())
  AD = [list(map(int, input().split())) for i in range(T)]

  for i in AD:
    A = i[0]
    B = i[1]
    C = i[2]
    D = i[3]
    if A < B:
      No()
      continue
    if B > D:
      No()
      continue
    add = D - B
    d = gcd(B, D)
    
    C += 1
    t = C % d
    k = A % d
    if k == t:
      LD = C
    elif k > t:
      LD = C + k - t
    else:
      LD = C + d - t + k
    if LD < B:
      No()
    else:
      Yes()

main()