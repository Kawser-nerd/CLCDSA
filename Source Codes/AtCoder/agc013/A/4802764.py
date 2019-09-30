n = int(input())
a = list(map(int, input().split()))

count = 1
increasing = None

for i in range(n-1):
  if increasing == None:
    if a[i] - a[i+1] > 0:
      increasing = True
    elif a[i] - a[i+1] < 0:
      increasing = False

  elif increasing:
    if a[i] - a[i+1] < 0:
      increasing = None
      count += 1

  elif not increasing:
    if a[i] - a[i+1] > 0:
      increasing = None
      count += 1
print(count)