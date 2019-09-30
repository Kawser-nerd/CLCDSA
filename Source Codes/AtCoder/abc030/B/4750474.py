n,m = map(int,input().split())

if n >=12:
    n -= 12
#n<12

short_r = 30*n+0.5*m
long_r = 6*m

result = abs(long_r-short_r)

if result>180:
    result = 360-result


print(result)