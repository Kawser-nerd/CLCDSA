N = int(input())
A = list(map(int, input().split()))

l=1; r=1

XOR = A[0]
SUM = A[0]

answer = 0

while True:
  if r < N: #r???????
    if XOR^A[r] == SUM + A[r]: #r?1???????
      XOR = XOR ^ A[r]
      SUM = SUM + A[r]
      r+=1
      continue
    else: # r?????????????l????
      if l==r: # r?l?1???
        answer +=1
        XOR = A[r]
        SUM = A[r]
        l+=1
        r+=1        
      else: # l??1???
        answer += r-(l-1)
        XOR = XOR ^ A[l-1]
        SUM = SUM - A[l-1]
        l+=1
  else:
    answer +=  (N-(l-1))*(N-(l-1)+1) //2 # (N-(l-1))C2
    break

print(answer)