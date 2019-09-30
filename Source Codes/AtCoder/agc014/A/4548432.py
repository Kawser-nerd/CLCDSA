def cookies_divide(num_of_per,A):
  
  if (A[0] == A[1] == A[2] and A[0]%2 + A[1]%2 + A[2]%2 == 0):
    return (-1,A)
  
  if(A[0]%2 + A[1]%2 + A[2]%2 > 0):
    return (0,A)
  
  R = [0 for i in range(num_of_per)]
  R[0] = A[1]//2 + A[2]//2
  R[1] = A[0]//2 + A[2]//2
  R[2] = A[0]//2 + A[1]//2
  return (1,R)

if(__name__== '__main__'):
  count = 0
  A = list(map(int,input().split()))
  while True:
    return_code, A = cookies_divide(3,A)
    if return_code < 0:
      print(return_code)
      break;
    
    if return_code == 0:
      print(count)
      break;
    
    count += return_code