N = int(input())
B = list(map(int,input().split()))
 
ans = []
while B:
    for i in range(len(B)-1, -1, -1):
        b = B[i]
        if i+1 == b:
            ans.append(i+1)
            break
    else:
        print(-1)
        exit()
    del B[i]
    
for idx in range(0, N):
	tmp = ans.pop(-1)
	print(tmp)