cx, cy, R = map(int, input().split())
l, d, r, u = map(int, input().split())
def c(x, y):
  return (x-cx)**2 + (y-cy)**2 > R**2
print("YES" if cx-R<l or cx+R>r or cy-R<d or cy+R>u else "NO")
print("YES" if c(l, u) or c(l, d) or c(r, u) or c(r, d) else "NO")