N = int(input())
H = [0]*N
S = [0]*N
 
for i in range(N):
    H[i], S[i] = map(int, input().split())
 
def check_P(p):
    #???P????????????????
    #p???????????????????????
    T = [0]*N
    for i in range(N):
        T[i] = int((p - H[i]) / S[i])
    sorted_index_T = sorted(range(len(T)), key=lambda k: T[k])
    for (k,i) in enumerate(sorted_index_T):
        if (T[i] < k):
            return False
    return True
 
#p?2??????
P_low = 0
P_high = 0
for i in range(N):
    p = H[i]
    if (P_low < p):
        P_low = p
    p = H[i] + S[i]*(N-1)
    if (P_high < p):
        P_high = p
P_low -= 1

while(True):
    P_now = int((P_low + P_high) / 2)
    #print(_, P_low, P_now, P_high)
 
    if (check_P(P_now)):
        P_high = P_now
    else:
        P_low = P_now
    if (P_high <= (P_low + 1)):
        print(P_high)
        break