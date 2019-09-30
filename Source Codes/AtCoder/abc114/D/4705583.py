import numpy as np
N = int(input())
p_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
dp = np.zeros([N, len(p_list)], dtype=int)
for i in range(2, N+1):
    for j in range(len(p_list)):
        x = p_list[j]
        power = 0
        while i%(x**(power+1)) == 0:
            power += 1
        dp[i-1, j] = dp[i-2, j] + power
factors = dp[-1]
num_g3 = len([1 for x in factors if x >= 2])
num_g5 = len([1 for x in factors if x >= 4])
num_g15 = len([1 for x in factors if x >= 14])
num_g25 = len([1 for x in factors if x >= 24])
num_g75 = len([1 for x in factors if x >= 74])
ans = 0
if num_g3 >= 3 and num_g5 >= 2:
    add = (num_g5*(num_g5-1))//2 * (num_g3-2)
    ans += add
if num_g15 >= 1:
    add = num_g15 * (num_g5-1)
    ans += add
if num_g25 >= 1:
    add = num_g25 * (num_g3-1)
    ans += add
if num_g75 >= 1:
    ans += num_g75
print(ans)