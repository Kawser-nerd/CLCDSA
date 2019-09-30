n = int(input())
a = [int(input()) for i in range(n)]
b,ans = [],0
for i,x in enumerate(a): b.append([x,i])
b.sort()
for i in range(n):
	if i%2!=b[i][1]%2: ans+=1
print(ans//2)