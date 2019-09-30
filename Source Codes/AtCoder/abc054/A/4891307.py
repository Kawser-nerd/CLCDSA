A,B = map(int,input().split())

if A==B:
  result = 'Draw'
elif (A < B and A!=1) or B==1:
  result = 'Bob'
else:
  result ='Alice'
print(result)