hoge=input()
n=int(input())
huga=[]
if(len(hoge)<n):
  print(0)
else:
  for i in range(len(hoge)-n+1):
    huga.append(hoge[i:n+i])

  huge=set(huga)
  print(len(huge))