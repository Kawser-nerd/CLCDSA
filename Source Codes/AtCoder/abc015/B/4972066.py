import math
import numpy as np
n = int(input())
n_list = list(map(int, input().split()))
count = 0
total = 0
for i in n_list:  
  if i != 0:
    count += 1
    total += i    
avrage = total / count
print(math.ceil(avrage))