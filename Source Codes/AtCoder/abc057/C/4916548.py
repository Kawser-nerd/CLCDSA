import math
n = int(input())
pf_list = []

min_digit = float('inf')
for i in range(1, int(math.sqrt(n))+1):
  if n % i == 0:
    a = len(str(int(i)))
    b = len(str(int(n/i)))
    tmp_list = [a, b]
    tmp_list = list(map(int, tmp_list))
    if min_digit > max(tmp_list):
      min_digit = max(tmp_list)

print(min_digit)