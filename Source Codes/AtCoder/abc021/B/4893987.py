def solve():
  n = int(input())
  a,b = (int(i) for i in input().split())
  k = int(input())
  p = list(int(i) for i in input().split())
  ans = 'YES'
  if a in p or b in p:
    ans = 'NO'
  if len(p) != len(set(p)):
    ans = 'NO' #???
  print(ans)
    
solve()