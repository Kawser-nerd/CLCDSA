n=int(input())
hoge=[]

for i in range(n):
  hoge.append(int(input()))
huga=list(set(hoge))

print(n-len(huga))