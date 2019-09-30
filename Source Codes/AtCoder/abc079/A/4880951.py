N = int(input())
if (N % 1000) % 111 == 0 or (N // 10) % 111 == 0:
  print("Yes")
else:
  print("No")