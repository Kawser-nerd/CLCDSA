import numpy as np
#S = str(input())
S = str(input())
N = len(S) - 1

def honyaku(ini,n):
    ans = np.zeros(n)
    for i in range(n-1,-1,-1):
        ans[i] = ini % 2
        ini = ini // 2
    return ans

def sum_list(list_domain,list_S):
    tmp = list_S[0]
    ans = 0
    for i in range(len(list_domain)):
        if list_domain[i] == 0:
            tmp = tmp*10 + list_S[i+1]
        else:
            ans += tmp
            tmp = list_S[i+1]
    return tmp + ans

list_S = np.zeros(N+1)
for i in range(N+1):
    list_S[i] = int(S[i])
ans = 0    
for i in range(2**N):
    list_domain = honyaku(i,N)
    ans += sum_list(list_domain,list_S)
    
print(int(ans))