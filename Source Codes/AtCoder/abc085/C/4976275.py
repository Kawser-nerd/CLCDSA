def comb(n,y):
    for i in range(n+1):
        for j in range(n+1-i):
            if 10000*i+5000*j+1000*(n-i-j)==y:
                return [i,j,n-i-j]
    return [-1,-1,-1]

n,y=map(int,input().split())
print("{} {} {}".format(*comb(n,y)))