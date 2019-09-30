N=int(input())
L=list(map(int,input().split()))

tn = len(list (filter (lambda x: x%2==0 and x%4!=0,L )))
tf = len(list(filter(lambda x: x%4==0,L)))

if tn==0 and (N-tn)//2 <= tf:
  print('Yes')
elif tn!=0 and 2*tf >= N-tn:
  print('Yes')
else: 
  print('No')