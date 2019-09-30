def solve():
  n = int(input())
  query = "b"
  s = input()
  if s == query:
    print("0")
    exit()
  tp = 0
  for i in range(50):
    if i%3 == 2:
      query = "b"+query+"b"
    elif i%3 == 0:
      query = "a"+query+"c"
    else:
      query = "c"+query+"a"
    tp += 1
    if query == s:
      print(tp)
      exit()
  print("-1")
solve()