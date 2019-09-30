n = int(input())
h,m,l = 0,0,0
for _ in range(n):
  a,b,c = sorted(list(map(int, input().split())))
  if h < c:
    h = c
  if m < b:
    m = b
  if l < a:
    l = a
print(h*m*l)