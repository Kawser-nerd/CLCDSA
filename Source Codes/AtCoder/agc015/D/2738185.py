import math
A = int(input())
B = int(input())
if B < A: A,B = B,A

if A == B:
    print(1)
else:
    t = int(math.floor(math.log2(B)))
    while (A & 2**t) == (B & 2**t):
        if A & 2**t:
            A -= 2**t
            B -= 2**t
        t-=1
    ans = 2**t - A              # [A,2^t-1]
    r = t-1
    while 2**t + 2**r > B and r>=0:
        r-=1
    # [2^t,2^t+2^{r+1}-1] \cup [2^t+A,2^{t+1}-1]
    C = 2**(r+1)
    if C < A:
        ans += C + 2**t - A
    else:
        ans += 2**t
    print(ans)