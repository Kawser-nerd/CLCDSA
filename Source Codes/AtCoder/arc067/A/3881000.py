import numpy as np
MOD = 10**9 + 7


def seachPrimeNum(N):
    max = int(np.sqrt(N))
    seachList = [i for i in range(2, N+1)]
    primeNum = []
    while seachList[0] <= max:
        primeNum.append(seachList[0])
        tmp = seachList[0]
        seachList = [i for i in seachList if i % tmp != 0]
    primeNum.extend(seachList)
    return primeNum


N = int(input())
if N == 1:
    print(1)
    exit()
N_list = seachPrimeNum(N)
ans_list = [0 for i in range(len(N_list))]
for i in range(2, N+1):
    temp_i = i
    for j in range(len(N_list)):
        while temp_i % N_list[j] == 0:
            temp_i = temp_i // N_list[j]
            ans_list[j] += 1
ans = 1
for i in range(len(ans_list)):
    ans = ans * (ans_list[i]+1) % MOD
print(ans)