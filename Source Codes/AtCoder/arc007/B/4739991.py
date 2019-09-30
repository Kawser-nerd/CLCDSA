N,M = map(int,input().split())
n_lis = [i for i in range(1,N+1)]
liscd = 0
for _ in range(M):
    cd = int(input())
    if cd in n_lis:
        case = n_lis.index(cd)
        n_lis[case] = liscd
        liscd = cd
for c in n_lis:
    print(c)