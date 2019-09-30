n=int(input())
hoge=[0,0,1]
for i in range(n):
  hoge.append((hoge[-1]+hoge[-2]+hoge[-3])%10007)
print(hoge[n-1])