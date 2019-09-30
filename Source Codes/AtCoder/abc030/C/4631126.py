from bisect import bisect_left as bs
n, m = map(int,input().split())
x, y = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
time = 0
cnt = 0
while True:
  ai = bs(a,time)
  if ai == n:
    break
  time = a[ai]+x
  bi = bs(b,time)
  if bi == m:
    break
  time = b[bi]+y
  cnt += 1
print(cnt)