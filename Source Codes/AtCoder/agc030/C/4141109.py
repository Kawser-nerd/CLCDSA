K  = int(input())
n = 0
n1 = 0
n2 = 0
n3 = 0
n4 = 0
n5 = 0


#K?500?????????????
if K <= 499:
   n = K
   mat = [[0 for n1 in range(K)] for n2 in range(K)]
   for n1 in range(K):
      for n2 in range(K-n1):
         mat[n1][n1+n2] = n2+1
   for n1 in range(K):
      for n2 in range(n1):
         mat[n1][n2] = K+n2-n1+1

#K?500?????????1???????????   
else:
   n = 500
   mat = [[0 for n1 in range(500)] for n2 in range(500)]
   for n1 in range(500):
      for n2 in range(500-n1):
         mat[n1][n1+n2] = n2+1
   for n1 in range(500):
      for n2 in range(n1):
         mat[n1][n2] = 500+n2-n1+1

   #K?500????????????
   for n2 in range(K-500):
      for n1 in range(250):
          kari = n1*2+n2
          if kari >= 500:
             kari = kari-500
          mat[n1*2][kari] = n2+501


#??????????? 
print(n)

if K <= 500:
   out = ""
   for n1 in range(K):
      out = ""   
      for n2 in range(K):
         out = out + " " + str(mat[n1][n2])
      print(out)
   
#K?500?????????1???????????   
else:
   out = ""
   for n1 in range(500):
       out = ""   
       for n2 in range(500):
          out = out + " " + str(mat[n1][n2])
       print(out)