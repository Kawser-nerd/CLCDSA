num_array = input()
gap = 1000    
for i in range(0, len(num_array) - 2):
    if  abs(753 - int(num_array[i:i+3])) < gap:
        gap = abs(753 - int(num_array[i:i+3]))
print(gap)