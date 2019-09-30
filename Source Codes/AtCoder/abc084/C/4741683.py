n = int(input())


csf =  [tuple(map(int,input().split())) for _ in range(n-1)]

# print(csf)

for i in range(n-1):

    ans = csf[i][0] + csf[i][1]

    for j in range(i+1,n-1):
        here = csf[j]
        
        ans = max(ans,here[1])
        
        rm = ans % here[2]
        if rm != 0:
            ans += here[2] - rm
            
        ans += here[0]

#        print(ans)
    print(ans)

print(0)