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

    N = int(input().rstrip())
    S = list(_ for _ in input())
    x = 0
    max_x = 0
    for s in S:        
        if s == 'I':
            x += 1
        elif s == 'D':
            x += -1
        max_x = max(x,max_x)
    print(max_x)
    
if __name__ == '__main__':
    main()