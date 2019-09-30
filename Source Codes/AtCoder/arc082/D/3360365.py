X = int(input())
K = int(input())
R = list(map(int, input().split()))
Q = int(input())


ami = [0]*(K+1)
ama = [X] + [0]*K
cusummi = [0]*(K+1)
cusumma = [0]*(K+1)
cusum = [0]*(K+1)
pr = 0
for i, r in enumerate(R):
    d = pr-r if i%2==0 else r-pr
    cusum[i+1] = cusum[i] + d
    cusummi[i+1] = min(cusummi[i], cusum[i+1])
    cusumma[i+1] = max(cusumma[i], cusum[i+1])
    ami[i+1] = min(max(ami[i] + d, 0), X)
    ama[i+1] = min(max(ama[i] + d, 0), X)
    pr = r

import bisect
for _ in range(Q):
    t, a = map(int, input().split())
    i = bisect.bisect_right(R, t)
    t1 = R[i-1] if i!=0 else 0
    t2 = t-t1
    d = -t2 if i%2==0 else t2
    if ama[i]==ami[i]:
        print(min(max(ama[i] + d, 0), X))
        continue
    ans = a+cusum[i]
    if -cusummi[i]>a:
        ans += -cusummi[i]-a
    if cusumma[i]>(X-a):
        ans -= cusumma[i]-(X-a)
    print(min(max(ans+d, 0), X))