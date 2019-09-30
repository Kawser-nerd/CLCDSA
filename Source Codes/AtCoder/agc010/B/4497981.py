n = int(input())
a = list(map(int,input().split()))
 
sum_a = sum(a)
len_a = len(a)
kaisu = sum_a // ( (1/2)*(len_a)*(len_a+1) )
 
if sum_a % ( (1/2)*(len_a)*(len_a+1) ) !=0:
  print("NO")
  exit()

ans_kaisu = 0
a.append(a[0])

for i in range(n):
  tmp = (kaisu - (a[i+1]-a[i])) // len_a
  if (kaisu - (a[i+1]-a[i])) % len_a !=0 or tmp < 0:
    print("NO")
    exit()
  ans_kaisu += tmp
  
if ans_kaisu ==kaisu:
  print("YES")
else:
  print("NO")