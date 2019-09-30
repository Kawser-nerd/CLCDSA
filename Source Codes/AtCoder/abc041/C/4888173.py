N = int(input())
al = list(map(int,input().split()))
bl = [( i ,al[i] )    for i in range(N) ]
bl.sort(reverse=True,key=lambda x: x[1])
for b in bl:
    print(b[0]+1)