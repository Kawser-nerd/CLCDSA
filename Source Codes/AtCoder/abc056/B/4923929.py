w, a, b = map(int, input().split())

if a < b:
  print(max(0, b-(a+w)))
elif a > b:
  print(max(0, a-(b+w)))
else:
  print(0)