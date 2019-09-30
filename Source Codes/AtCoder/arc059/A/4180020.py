n=int(input())
a=list(map(int,input().split()))
l=[]
for i in range(min(a),max(a)+1):
  cnt=0
  for j in a:
    cnt+=(i-j)**2
  l.append(cnt)
print(min(l))