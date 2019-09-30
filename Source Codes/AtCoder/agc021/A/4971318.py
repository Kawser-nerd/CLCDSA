N = list(input())
ans1,ans2 = 0,0
for i in range(len(N)):
    if(i == 0): ans1 += int(N[i])-1
    else: ans1 += 9
    ans2 += int(N[i])   
 
ans = max(ans1,ans2)
print(ans)