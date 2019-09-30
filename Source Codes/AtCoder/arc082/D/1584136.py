X = int(input())
K = int(input())
R = [int(x) for x in reversed(input().split())]
for i in range(0,K-1): R[i] -= R[i+1]
Q = int(input())

aM = X
M = X
am = 0
m = 0
now = 0
sign = -1
timer = R.pop()

def Go(time):
    global aM,M,am,m
    if sign==1:
        if m+time>X:
            m = X
            M = X
            aM = am
        elif M+time>X:
            m += time
            M = X
            aM = am + M - m
        else:
            m += time
            M += time
    else:
        if M-time<0:
            m = 0
            M = 0
            am = aM
        elif m-time<0:
            m = 0
            M -= time
            am = aM + m - M
        else:
            m -= time
            M -= time

for i in range(Q):
    t,a = [int(x) for x in input().split()]
    t -= now
    now += t
    
    while t>=timer:
        Go(timer)
        t -= timer
        if R:
            timer = R.pop()
        else:
            timer = float("inf")
        sign *= -1
    
    Go(t)
    timer -= t
    
    if a<am:
        print(m)
    elif a>aM:
        print(M)
    else:
        print(m+a-am)