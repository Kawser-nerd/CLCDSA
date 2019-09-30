N, M, A, B = map(int, input().split())
short = []
flg = 0
for i in range(M):
    if N <= A:
        N = N + B
    N = N - int(input())
    if N < 0:
        short.append(i+1)
        flg = 1
if flg == 0:
    print('complete')
else:
    print(min(short))