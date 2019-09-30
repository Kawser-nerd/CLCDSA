import numpy as np

N = int(input())
H = np.zeros(N, dtype=np.int)
S = np.zeros(N, dtype=np.int)
th = np.arange(N)

for i in range(N):
    H[i], S[i] = map(int, input().split())
 
def check_P(p):
    #???P????????????????
    #p???????????????????????
    T = np.floor((p - H) / S)
    return np.all(np.sort(T) >= th)
 
#p?2??????
P_low = np.max(H) - 1
P_high = np.max(H+S*(N-1))

while((P_high - P_low) > 1):
    P_now = np.int((P_low + P_high) / 2)
    #print(P_low, P_now, P_high)
 
    if (check_P(P_now)):
        P_high = P_now
    else:
        P_low = P_now
print(P_high)