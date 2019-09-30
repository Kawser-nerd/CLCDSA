n = input()
num_list = list(n)
num_list = [int(i) for i in num_list]
for i in range(3):
  if num_list[i] == 1:
    num_list[i] = 9
  elif num_list[i] == 9:
    num_list[i] = 1
print(''.join([str(i) for i in num_list]))