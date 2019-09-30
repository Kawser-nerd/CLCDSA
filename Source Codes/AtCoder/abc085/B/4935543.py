import sys
unique_list = []
input_list = sys.stdin.readlines()[1:]
for i in input_list:
    if i not in unique_list:
        unique_list.append(i)
print(len(unique_list))