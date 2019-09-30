n=int(input())
s=[input() for __ in range(n)]
names=set(s)
num=0
for name in names:
    if num < s.count(name):
        ans=name
        num=s.count(name)
print(ans)