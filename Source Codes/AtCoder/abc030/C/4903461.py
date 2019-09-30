import bisect
N , M = map(int,input().split())
X , Y = map(int,input().split())
al = list(map(int,input().split()))
bl = list(map(int,input().split()))
a , b = 0 , 0
# ??A??????B???
# ?????t
t  =  0
ans = 0
# ??????????????
while al[-1] >= t and bl[-1] >= t:
    # ??A?????
    a = bisect.bisect_left(al , t)
    #print("from_a:a:t:ans",a,t,ans)
    if  a >= N - 1 and al[-1] < t:
        break
    # ??A???B???????    
    t = al[a] + X
    # ??B?????
    b = bisect.bisect_left(bl , t)
    #print("from_b:b:t:ans",b,t,ans)
    if  b >= M - 1 and bl[-1] < t:
        break
    # ??A???B???????    
    ans += 1
    t = bl[b] + Y
    #print("arrive_a:t:ans",t,ans)
print(ans)