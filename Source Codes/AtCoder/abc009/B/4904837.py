n=int(input())
hoge=[]
for i in range(n):
  hoge.append(int(input()))
hoge=list(set(hoge))
hoge.sort(reverse=True)
print(hoge[1])