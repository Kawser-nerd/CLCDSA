N = int(input())
S = 0
s_list = []

input_list = list(map(int, input().split()))
allS = sum(input_list)

for n in input_list[:-1]:
  S += n
  s_list.append(abs(allS - 2 * S))
  
print(min(s_list))