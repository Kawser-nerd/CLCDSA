H_1, W_1 = map(int,input().split())
H_2, W_2 = map(int,input().split())
if H_1 == H_2 or H_1 == W_2 or W_1 == H_2 or W_1 == W_2:
  print("YES")
else:
  print("NO")