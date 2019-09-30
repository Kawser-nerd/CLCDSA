Ps = range(1000001)
Ps[1] = 0
p = 2
while (p < 1000):
    if (Ps[p]):
        Ps[p*p::p] = [0] * (1 + (1000000 / p) - p)
    p += 1
Ps = [p for p in Ps if p]

dunno = "I don't know."

for casenum in xrange(1,1+int(raw_input())):
    [D,K] = [int(z) for z in raw_input().split()]
    s = [int(z) for z in raw_input().split()]
    ans = dunno
    if K > 1:
        if s[-1] in s[:-1]:
            for z in xrange(K):
                if s[-1] == s[z]:
                    ans = s[z+1]
                    break
        else:
            if K > 2:
                pl = [z for z in Ps if z < (10 ** D)]
                for p in pl:
                    if p <= max(s):
                        continue
                    x = (s[1] - s[0])
                    if (x < 0):
                        x += p
                    y = (s[2] - s[1])
                    if (y < 0):
                        y += p
                    A = 0
                    while (A < p):
                        if ((A * x) % p) == y:
                            break
                        A += 1
                    B = (s[1] - ((A * s[0]) % p))
                    if (B < 0):
                        B += p
                    valid = True
                    for k in range(len(s)-1):
                        if s[k+1] != ((A * s[k] + B) % p):
                            valid = False
                            break
                    if valid:
                        num_ans = str(((A * s[-1] + B) % p))
                        if ans == dunno:
                            ans = num_ans
                        elif ans == num_ans:
                            continue
                        else:
                            ans = dunno
                            break
    print ("Case #%d: " % casenum) + str(ans)
