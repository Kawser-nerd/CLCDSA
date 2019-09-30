N = int(input())
dic = {}
list1 = ['M','A','R','C','H']
list2 = [0,0,0,0,0]
for i in range(N):
  s = list(input())
  s = s[0]
  for j in range(5):
   if(s == list1[j]):
    list2[j] += 1

a,b,c,d,e = list2[0],list2[1],list2[2],list2[3],list2[4]
ans = a*b*c + a*b*d + a*b*e + a*c*d + a*c*e + a*d*e
ans += b*c*d + b*c*e + b*d*e 
ans += c*d*e
print(ans)