N = int(input())
A = list(map(int,input().split()))
A.insert(0,0)
A.append(0)

sum_all = 0
for i in range(N+2):
 if(i != 0):
  sum_all += abs(A[i]-A[i-1])

#???????????????????
#(ex) a b c 
#-> cost_prev = abs(a-b) + abs(b-c)
#b??
#-> a c
#-> cost_after = abs(a-c)
#ans = sum_all - cost_prev + cost_after
for i in range(N+2):
  if((i != 0)and(i != N+1)):
    cost_prev = abs(A[i-1]-A[i])+abs(A[i]-A[i+1])
    cost_after = abs(A[i-1]-A[i+1])
    ans = sum_all - cost_prev + cost_after
    print(ans)