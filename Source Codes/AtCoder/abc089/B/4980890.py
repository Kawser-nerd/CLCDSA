n=int(input())
arr=list(map(str,input().split()))
count=0
if arr.count('P')!=0:
  count+=1
if arr.count('Y')!=0:
  count+=1
if arr.count('W')!=0:
  count+=1
if arr.count('G')!=0:
  count+=1
if count==3:
  print('Three')
if count==4:
  print('Four')