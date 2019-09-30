S = sorted([i for i in input()])
N = int(input())
count = 0
for i in range(len(S)):
  for j in range(len(S)):
        count+=1
        if count==N:
              print(S[i]+S[j])