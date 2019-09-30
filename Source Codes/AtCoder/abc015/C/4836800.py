N, K = map(int, input().split())

T = []
for i in range(N):
    T.append(list(map(int, input().split())))

def func(cnt, val):
    if cnt==N:
        return val == 0
    for i in range(K):
        if func(cnt+1, val^T[cnt][i]):
            return True
    return False

if func(0, 0):
    print('Found')
    
else:
    print('Nothing')