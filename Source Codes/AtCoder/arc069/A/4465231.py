N,M = map(int,input().split())

if N < int(M/2):
    res = N
    M -= N*2
    if M >= 4:
        res += int(M/4)
else:
    res = int(M/2)

print(res)