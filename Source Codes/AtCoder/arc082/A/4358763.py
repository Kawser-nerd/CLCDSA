N = int(input())

A = list(map(int, input().split()))

counter = [0] * 100001

for a in A:
  if a:
    counter[a-1]+=1
    counter[a]+=1
    counter[a+1]+=1
  else:
    counter[a]+=1
    counter[a+1]+=1

print(max(counter))