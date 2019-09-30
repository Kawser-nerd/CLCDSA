import sys
l1, l2 = [sys.stdin.readline().strip() for i in range(2)]
input_list = [int(i) for i in l2.split()]
input_list.sort(reverse=True)
odd_index = [j for i, j in enumerate(input_list) if i%2 != 0]
even_index = [j for i, j in enumerate(input_list) if i%2 == 0]
print(sum(even_index) - sum(odd_index))