a, b, c = map(int, input().split())
lst = [a, b, c]
for i in lst:
  if lst.count(i)%2==1:
    print(i)
    break