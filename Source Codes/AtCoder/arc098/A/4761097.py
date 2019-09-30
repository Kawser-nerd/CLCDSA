from sys import stdin
import numpy as np

N = int(stdin.readline().rstrip().split()[0])
# A = [int(x) for x in stdin.readline().rstrip().split()]
# N, X = [int(x) for x in stdin.readline().rstrip().split()]
S = stdin.readline().rstrip().split()[0]

is_w_list = [1 if s=="W" else 0 for s in S ]
cumsum_w = np.append(np.array([0]),(np.cumsum(is_w_list)[:-1])) 

is_e_list = [not(x) for x in is_w_list[::-1]]
cumsum_e = np.append(np.array([0]),(np.cumsum(is_e_list)[:-1]))[::-1]
# print(cumsum_e+cumsum_w)
print(np.min(cumsum_w+cumsum_e))