N = int(input())
A = [int(i) for i in input().split()]

I = [x>y for x,y in zip([0]+A,A+[10**10])]          
D = [x<y for x,y in zip([10**10]+A,A+[0])]          

ci = False
cd = False
ans = 1
for i in range(N+1): 
    ci += I[i]
    cd += D[i]
    if ci and cd:
        ans += 1
        ci = False
        cd = False
print(ans)