N=input()

for i in range(len(N)):
    if N[i] == 3:
        ans = True
    elif int(N)%3 == 0:
        ans = True
    else: ans = False

if ans == True:
    print("YES")
    
else:
    print("NO")