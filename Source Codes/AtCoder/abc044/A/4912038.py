max = int(input())
sam = int(input())
sam_num = int(input())
sam_later= int(input())

if(max<sam):
  print(sam_num*max)
else:
  print(sam_num * sam + sam_later * (max-sam))