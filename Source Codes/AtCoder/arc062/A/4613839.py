n = int(input())
t2, a2 = map(int, input().split())
for _ in range(n-1):
  t, a = map(int, input().split())
  m = max((t2-1)//t, (a2-1)//a)+1
  t2 = m*t
  a2 = m*a
print(t2+a2)