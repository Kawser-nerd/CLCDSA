n=int(input())
d=[int(input())for i in range(n)]
d.sort()
print(sum(d))
ans=d[-1]
del d[-1]
if sum(d)>ans:print(0)
else:print(ans-sum(d))