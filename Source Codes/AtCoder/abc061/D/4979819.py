from functools import reduce
import math

def main():
    # ????2????????
    # '101' ? '5'
    # ??????'0b'????int()????
    # binary = int('0b'+'101',0)

    # 2????????bit????
    # 101(0x5) ? 2
    # cnt_bit = bin(5).count('1')
    
    # N! ????
    # f = math.factorial(N)
    
    # ????
    # 4 // 3
    # ????
    #-(-4 // 3)
    
    # ????:??????(100?)
    INF = float("inf")

    # ????:??????(-100?)
    # -INF = float("inf")
    
    # 1?????????
    # ??:2
    # a = input().rstrip()
    # ??:a='2'
    
    # ??????????????????????
    # ??:2 4 5 7
    # a, b, c, d = (int(_) for _ in input().split())  
    # ??:a=2 b=4 c=5 d =7
    
    # 1??????????????????
    # ??:2 4 5 7
    # a = list(int(_) for _ in input().split())
    # ??:a = [2, 4, 5, 7]    

    # 1??????????????????
    # ??:2457
    # a = list(int(_) for _ in input())
    # ??:a = [2, 4, 5, 7]    
    N,M = (int(_) for _ in input().split())
    a = []
    b = []
    c = []
    d = [INF]*N
    
    for i in range(M):
        s1, s2, s3 = (int(_) for _ in input().split())
        a.append(s1)
        b.append(s2)
        c.append(-s3)
    d[0] = 0
    cnt = [0]*N
    for j in range(N):
        update=False
        for i in range(M):
            if math.isinf(d[a[i]-1]):
                continue
            if(d[b[i]-1] > d[a[i]-1]+c[i]):
                d[b[i]-1] = d[a[i]-1]+c[i]
                cnt[b[i]-1]+=1
                update=True
        if not update:
            break
    if cnt[N-1] < N:
        ans = -d[N-1]
    else:
        ans = 'inf'
    
    # negative = [False]*N
    # for j in range(N):
    #     for i in range(M):
    #         if(d[a[i]-1] == 1e10):
    #             continue
    #         if(d[b[i]-1] > d[a[i]-1]+c[i]):
    #             d[b[i]-1] = d[a[i]-1]+c[i]
    #             negative[b[i]-1] = True
    #         if(negative[a[i]-1]):
    #             negative[b[i]-1] = True
    print(ans)
if __name__ == '__main__':
    main()