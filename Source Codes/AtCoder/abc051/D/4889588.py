from functools import reduce

def main():
    # ????
    # 4 // 3
    # ????
    #-(-4 // 3)
    
    # ????:??????(100?)
    # 1e10

    # ????:??????(-100?)
    # -1e10
    
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
    N, M = (int(_) for _ in input().split())
    d = [[1e10 for _ in range(N)] for _ in range(N)]
    a = []
    b = []
    c = []
    for i in range(M):
        ai, bi, ci = (int(_) for _ in input().split())
        d[ai-1][bi-1] = ci
        d[bi-1][ai-1] = ci
        a.append(ai-1)
        b.append(bi-1)
        c.append(ci)
        
    for i in range(N):
        d[i][i] = 0       
        
    for i in range(N):
        for j in range(N):
            for k in range(N):
                d[j][k] = min(d[j][i]+d[i][k],d[j][k])

    ans = M
    for i in range(M):
        is_shortest = False
        for j in range(N):
            if(d[j][a[i]]+c[i] == d[j][b[i]]):
                is_shortest = True
        if is_shortest:
            ans -= 1
    print(ans)
    
if __name__ == '__main__':
    main()