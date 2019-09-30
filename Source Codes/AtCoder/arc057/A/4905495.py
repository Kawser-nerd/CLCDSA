A, K = list(map(int, input().split()))
X = int(2e12)

if K==0:
    print(X-A)
    exit()

day=0
while A<X:
  A=1+(K+1)*A
  day+=1
  
print(day)