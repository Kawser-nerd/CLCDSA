from functools import reduce
import math
import itertools

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
    for i in range(M):
        c, d = (int(_) for _ in input().split())
        a.append(c)
        b.append(d)
    l = list(_ for _ in range(2,N+1))
    d = []
    for elem in itertools.permutations(l,len(l)):
        elem = list(elem)
        elem.insert(0,1)
        d.append(elem)
    ans = 0
    for l1 in d:
        flag = True
        for i in range(len(l1)-1):
            for j in range(M):
                if(a[j]==l1[i] and b[j] ==l1[i+1]) or (b[j]==l1[i] and a[j] ==l1[i+1]):
                    flag = True
                    break
                flag = False
            if flag == False:
                break
        if flag:
            ans += 1

    print(ans)
if __name__ == '__main__':
    main()