N = input()
N_list = [int(i) for i in N]

if N_list[0] == N_list[1] == N_list[2] or N_list[1] == N_list[2] == N_list[3]:
  print("Yes")
else:
  print("No")