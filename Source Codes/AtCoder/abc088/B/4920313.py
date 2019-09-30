n=int(input())
card=list(map(int,input().split()))
card=sorted(card)[::-1]
Alice=[]
Bob=[]
for i in range(n):
  if i%2==0:
    Alice.append(card[i])
  else:
    Bob.append(card[i])
print(sum(Alice)-sum(Bob))