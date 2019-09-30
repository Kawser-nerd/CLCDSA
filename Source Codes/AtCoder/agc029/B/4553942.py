from collections import Counter
N = int(input())
A_arr = list(map(int, input().split()))

A_arr = sorted(A_arr, reverse=True)
C_arr = Counter(A_arr)

count = 0
for i in range(N):
    v_max = A_arr[i]
    if C_arr[v_max] == 0:
        continue
    C_arr[v_max] -= 1
    v_pair = 2**v_max.bit_length() - v_max
    if C_arr[v_pair] > 0:
        C_arr[v_pair] -= 1
        count += 1
    else:
        pass

print(count)