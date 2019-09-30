n=int(input())
ans=set()
for i in map(int,input().split()):
  while i%2==0:
    i//=2
  ans.add(i)
print(len(ans))