#sys.stdin.readline()
import sys
input = sys.stdin.readline
N,K = map(int,input().split())
A = list(map(int,input().split()))

#??A??????1???
#(ex) (K=3)[1,1,1,8,4,6,2,5] -> 2?(k-1?)??1????????
#?????????????

min_index = A.index(1)
#????????????,???????1?
if(min_index > N//2):
  A.reverse()
  
count = 0
while(1):
  min_index = A.index(1)
  if(min_index == 0):
    break
  if((min_index-(K-1)) >= 0):
    del A[min_index-(K-1):min_index]
  elif((min_index-(K-1)) < 0):
    x = min_index - 1
    del A[0:x+1]
    y = K - min_index - 1
    del A[1:y+1]
  count += 1

if((len(A)-1)%(K-1) == 0):
 count += (len(A)-1)//(K-1)
else:
 count += (len(A)-1)//(K-1) + 1

print(count)