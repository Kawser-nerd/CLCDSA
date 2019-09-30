def solve():
  n = int(input())
  a = list(int(i) for i in input().split())
  query = []
    
  
  
  
  for i in a:
    while i%2 != 1:
      i /= 2
    query.append(i)
  
  ans = len(set(query))
  print(ans)
solve()