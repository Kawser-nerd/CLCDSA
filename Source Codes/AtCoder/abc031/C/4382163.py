N = int(input())
A = list(map(int, input().split()))

takahasi = -10 ** 5
for i in range(N):
    aoki = -(10 ** 10)
    for j in range(N):
        tmp1 = 0
        tmp2 = 0
        if i < j:
            for k in range(i, j+1):
                if (i - k)%2 == 0:
                    tmp1 += A[k]
                else:
                    tmp2 += A[k]
                    
            if aoki < tmp2:  
                aoki = tmp2
                t_tmp = tmp1
            
        if i > j:
            for k in range(j, i+1):
                if (j - k)%2 == 0:
                    tmp1 += A[k]
                else:
                    tmp2 += A[k]
                    
            if aoki < tmp2:
                aoki = tmp2
                t_tmp = tmp1
            
    takahasi = max(takahasi, t_tmp)
    
print(takahasi)