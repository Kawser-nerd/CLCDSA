a = int(input())
b = int(input())
c = int(input())
i = c
while True:
  if i%a == 0 and i%b == 0:
    print(i)
    break
  else:
    i += 1