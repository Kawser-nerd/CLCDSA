from functools import reduce
import math

def main():
    # N! ????
    # f = math.factorial(N)
    
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
    N,M = (int(_) for _ in input().split())
    a = []
    b = []
    c = []
    d = []
    ans = []
    for i in range(N):
        t1, t2 = (int(_) for _ in input().split())  
        a.append(t1)
        b.append(t2)
    for i in range(M):
        t1, t2 = (int(_) for _ in input().split())  
        c.append(t1)
        d.append(t2)

    for i in range(N):
        min_dist = 1e10
        ans.append(0)
        for j in range(M):
            dist = abs(a[i]-c[j])+abs(b[i]-d[j])
            if min_dist > dist:
                ans[i] = str(j+1)
                min_dist = dist
    print('\n'.join(ans))
    
if __name__ == '__main__':
    main()