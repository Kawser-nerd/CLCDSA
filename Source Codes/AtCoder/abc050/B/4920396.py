N = int(input())
T = [int(i) for i in input().split()]
M = int(input())

L = []
for i in range(M):
    p,x = map(int, input().split())
    L.append((p,x))
    
T_sum = sum(T)
for i in L:
    check = T[i[0]-1] - i[1]
    print(T_sum - check)