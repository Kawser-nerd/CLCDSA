N = input()     

ans = sum([int(i) for i in N])

tmp = int(N[0])-1
for i in range(1,len(N)):
    tmp += 9
print(max(ans,tmp))