n, m = map(int, input().split())
a = [int(input()) for _ in range(m)]
a = a[::-1] + list(range(1,n+1))
s = set()
for i in a:
  if i not in s:
    print(i)
    s.add(i)