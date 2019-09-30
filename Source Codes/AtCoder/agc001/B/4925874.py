n, x = [int(i) for i in input().split()]

cnt=0

short = min(x,n-x)
long  = max(x, n-x)
cnt += n
#cnt += x*(2*(n//x)-1) + (n-x)

while(1):
    c = long % short
    a = long //short
    if c==0:
        break
    else:
        cnt += short * 2 * a
        long = short
        short = c

cnt += short * (2 * a -1)
print(cnt)