n = int(input())

l_i = 0
l_i_1 = 1
l_i_2 = 2

if n == 1:
  print("1")
else:
  for i in range(n-1):
    l_i = 0
    l_i = l_i_1 + l_i_2
    l_i_2 = l_i_1
    l_i_1 = l_i
  print(l_i)