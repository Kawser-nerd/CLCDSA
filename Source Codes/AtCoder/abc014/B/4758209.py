n,X=map(int,input().split())
a_lst=list(map(int,input().split()))
binary=list(bin(X)[2:])[::-1]
ans = 0
for i in range(len(binary)):
	if binary[i]=='1':
		ans += a_lst[i]
print(ans)