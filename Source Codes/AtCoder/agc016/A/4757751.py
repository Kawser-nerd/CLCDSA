S = input()
N = len(S)

for i in range(1,N+1):   
    s = {x for x in S}
    for j in range(N+1-i):
        s &= {x for x in S[j:j+i]}
        if s==set():
            break
    else:
        break   
print(i-1)