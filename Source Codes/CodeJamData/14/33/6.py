import math
import heapq


def test(N, M, K, t, b, limit):
    stone = t + b
    cover = t + b
    layer = 2
    
    while layer <= M:
#        print(t, b, stone, cover, layer)
        if cover >= K and t - b <= 2:
            return stone
        else:
            stone += 2
            b = min(N, b+2)
            cover += b
            if b > t:
                t, b = b, t
            layer += 1
        if stone > limit:
            break
    return -1
    

def main():
    ifile = open('c.in', 'r')
    ofile = open('c.out', 'w')

    T = int(ifile.readline().strip())
    for case in range(1, T+1):
    
        N, M, K = [int(x) for x in ifile.readline().split()]

        m = K
        for i in range(1,N+1):
            for j in range(1, i+1):
                t = test(N, M, K, i, j, m)
                if t > 0 and t < m:
                    m = t
#                    print(i, j, t)

        N, M = M, N
        for i in range(1,N+1):
            for j in range(1, i+1):
                t = test(N, M, K, i, j, m)
                if t > 0 and t < m:
                    m = t
#                    print(i, j, t)     

#        if N < M:
#            N, M = M, N

                    

        
            

        
#        print('CASE:', case, m)
        ofile.write('Case #%d: %d\n' %(case, m))


        

if __name__ == "__main__":
    main()
