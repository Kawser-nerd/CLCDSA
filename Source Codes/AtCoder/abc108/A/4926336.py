import numpy as np
import itertools

a = int(input())

odd_list = np.arange(1, a+1, 2)
even_list = np.arange(2, a+1, 2)
count = 0
for odd, even in itertools.product(odd_list, even_list):
    #print(odd,even)
    count += 1
    
print(count)