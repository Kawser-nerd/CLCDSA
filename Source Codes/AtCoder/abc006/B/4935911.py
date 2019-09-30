def trib(n):
   a, b, c = 0, 0, 1
   for i in range(n-1):
     a, b, c = b, c, (a+b+c)%10007
   print(a) 

n = int(input())
trib(n)