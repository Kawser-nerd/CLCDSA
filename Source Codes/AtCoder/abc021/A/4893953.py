def solve():
  n = int(input())
  if n%2 == 1:
    query = [1]
    n -= 1
  else:
    query = []
  while n > 1:
    n = n//2
    query.append(2)

    
  print(len(query))
  for i in query:
    print(i)
  
solve()