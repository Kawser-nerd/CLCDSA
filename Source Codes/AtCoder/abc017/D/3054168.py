n,m = (int(i) for i in input().split())
f = int(input())
last,t = [0 for i in range(m+1)],[1,2]
last[f],num,mod,ans = 1,1,10**9+7,[1,1]
for i in range(2,n+1):
	f = int(input())
	if num>last[f]:
		ans.append((ans[-1]*2)%mod)
	elif num==1:
		ans.append((ans[-1]*2-t[last[f]-1])%mod)
		num = last[f]+1
	else:
		ans.append((ans[-1]*2-t[last[f]-1]+t[num-2])%mod)
		num = last[f]+1
	t.append((t[-1]+ans[-1])%mod)
	last[f] = i
print(ans[-1])