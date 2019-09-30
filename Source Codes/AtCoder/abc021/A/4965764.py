n=int(input())
for i in range(2):
  for j in range(2):
    for k in range(2):
      for l in range(2):
        if i*8+j*4+k*2+l*1==n:
          print(i+j+k+l)
          if i==1:
            print(i)
          if j==1:
            print(j)
          if k==1:
            print(k)
          if l==1:
            print(l)