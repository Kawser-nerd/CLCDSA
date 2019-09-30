n=int(input())
hoge=list(map(int,input().split()))

bunbo=len(hoge)-hoge.count(0)

bunsi=sum(hoge)

if(bunsi%bunbo==0):
  print(int(bunsi/bunbo))
else:
  print(int(bunsi/bunbo)+1)